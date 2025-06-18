https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/
// this is MERGE-INTERVAL-PATTERN, because here we are dividing into two intervals and merging the answer
class Solution {
    public:
    
        int recursion(int start, int end){
            // when we are at last element, then it's right guess so no panelty, if start is more than end then also no panelty
            if(start >= end)
                return 0;
    
    
            // iterate on each number from left to right for starting point and find out the panelty if we choose current number
            int ans = INT_MAX;
            for(int i=start;i<=end;i++){
    
                int left_ans = recursion(start,i-1);
                int right_ans = recursion(i+1,end);
    
                // from left and right side, we need maximum panelty and add it to the current panelty
                int subset_ans = i + max(left_ans,right_ans);
    
                ans = min(ans,subset_ans);
    
            }
    
            return ans;
     
        }
    
        int top_down_dp(int start, int end,vector<vector<int>>& dp){
            // when we are at last element, then it's right guess so no panelty, if start is more than end then also no panelty
            if(start >= end)
                return 0;
    
            if(dp[start][end] != -1)
                return dp[start][end];
    
            // iterate on each number from left to right for starting point and find out the panelty if we choose current number
            int ans = INT_MAX;
            for(int i=start;i<=end;i++){
    
                int left_ans = top_down_dp(start,i-1 ,dp);
                int right_ans = top_down_dp(i+1,end,dp);
    
                // from left and right side, we need maximum panelty and add it to the current panelty
                int subset_ans = i + max(left_ans,right_ans);
    
                ans = min(ans,subset_ans);
    
            }
    
            dp[start][end] = ans;
            return dp[start][end];
     
        }
    
       int bottom_up_dp(int n){
            vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    
            for(int start = n; start >= 1 ; start--){
                for(int end = 1;end <= n; end++){
                    
                    if(start >= end)
                        continue;
                    
                    // iterate on each number from left to right for starting point and find out the panelty if we choose current number
                    int ans = INT_MAX;
                    for(int i=start;i<=end;i++){
    
                        int left_ans = dp[start][i-1];
                        int right_ans = dp[i+1][end];
    
                        // from left and right side, we need maximum panelty and add it to the current panelty
                        int subset_ans = i + max(left_ans,right_ans);
    
                        ans = min(ans,subset_ans);
    
                    }
    
                    dp[start][end] = ans;
    
                }
            }
    
            return dp[1][n];
     
        }
    
        int getMoneyAmount(int n) {
            //return recursion(1,n); // time - exponetial
    
            // top down dp, time - o(n^3), space - o(n^2)
            // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
            // return top_down_dp(1,n,dp);
    
            // bottom_up_dp , time - o(n^3), space - o(n^2)
            return bottom_up_dp(n);
        }
    };