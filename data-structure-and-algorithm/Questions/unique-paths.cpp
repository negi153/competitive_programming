// https://leetcode.com/problems/unique-paths/description/
class Solution {
public:

    int recursion(int m,int n, int i, int j){
        if(i >= m || j>= n)
            return 0;

        if(i==m-1 && j==n-1)
            return 1;

        return recursion(m,n,i+1,j) + recursion(m,n,i,j+1);
    }

    int top_down_dp(int m,int n, int i, int j,vector<vector<int>>& dp){
        if(i >= m || j>= n)
            return 0;

        if(i==m-1 && j==n-1)
            return 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        dp[i][j] = top_down_dp(m,n,i+1,j,dp) + top_down_dp(m,n,i,j+1,dp);
        return dp[i][j];
    }

    int bottom_up_dp(int m,int n){
        vector<vector<int>> dp(m+5,vector<int>(n+5,0));

        dp[m-1][n-1] = 1;
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1)
                    continue;

                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }

        return dp[0][0];
    }

    int uniquePaths(int m, int n) {
        // return recursion(m,n,0,0);

        // top down dp
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return top_down_dp(m,n,0,0,dp);

        // bottom up dp
        return bottom_up_dp(m,n);
    }
};