// leetcode easy - https://leetcode.com/problems/climbing-stairs/description/

class Solution {
public:

    int recursion(int n){
        if(n==1)
            return 1;
        if(n==2)
            return 2;

        int ans = recursion(n-1) + recursion(n-2);
        return ans;
    }

    int topBottomDP(int n,vector<int>& dp){
        if(n==1)
            return 1;
        if(n==2)
            return 2;

        if(dp[n] != -1)
            return dp[n];

        dp[n] = topBottomDP(n-1,dp) + topBottomDP(n-2,dp);
        return dp[n];
    }

    int bottomUpDP(int n){

        vector<int> dp(n+2,-1);
        dp[1]=1;
        dp[2]=2;

        for(int i=3;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2];

        return dp[n]; 
    }

    int spaceOptimizeDP(int n){

        if(n==1)
            return 1;
        if(n==2)
            return 2;
            
        int prev2= 1;
        int prev1 = 2;
        int curr;
        for(int i=3;i<=n;i++){
            curr = prev2 + prev1;
            prev2 = prev1;
            prev1= curr;

        }
            
        return curr;
    }

    int climbStairs(int n) {
        // int ans = recursion(n); // brute force - TLE

        // vector<int> dp(n+1,-1); // top down approach -> recursion + memoization
        // int ans = topBottomDP(n,dp);

        // int ans = bottomUpDP(n); // bottom up approach -> tabulation -> iterative

        // space optimized
        int ans = spaceOptimizeDP(n);


        return ans;
    }
};