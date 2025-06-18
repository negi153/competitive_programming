https://leetcode.com/problems/perfect-squares/

class Solution {
    public:
    
        int recursion(vector<int>& arr, int target){
            if(target == 0)
                return 1;
            
            if(target < 0)
                return INT_MAX;
            
            // check by taking all the elemetns
            int ans = INT_MAX;
            for(int i=0;i<arr.size();i++){
                int recAns = recursion(arr,target-arr[i]);
    
                if (recAns != INT_MAX)
                    ans = min(ans,1 + recAns);
            }
    
            return ans;
        }
        
        int top_down_dp(vector<int>& arr, int target,vector<int>& dp){
            if(target == 0)
                return 1;
            
            if(target < 0)
                return INT_MAX;
            
            if(dp[target] != -1)
                return dp[target];
    
            // check by taking all the elemetns
            int ans = INT_MAX;
            for(int i=0;i<arr.size();i++){
                int recAns = top_down_dp(arr,target-arr[i],dp);
    
                if (recAns != INT_MAX)
                    ans = min(ans,1 + recAns);
            }
    
            dp[target] = ans;
            return dp[target];
        }
    
        int bottom_up_dp(vector<int>& arr, int target){
        
            vector<int> dp(target+3,0);
            dp[0] = 1;
    
    
            for(int tg = 1;tg<=target;tg++){
    
                // check by taking all the elemetns
                int ans = INT_MAX;
                for(int i=0;i<arr.size();i++){
                    if (tg-arr[i] >= 0){
                        int recAns = dp[tg-arr[i]];
    
                        if (recAns != INT_MAX)
                            ans = min(ans,1 + recAns);
                    }
        
                }
    
                dp[tg] = ans;
    
            }
    
    
            return dp[target];
        }
    
        int numSquares(int n) {
            vector<int> sqr;
    
            for(int i= 1;i*i<=n;i++)
                sqr.push_back(i*i);
    
            int target = n;
            // recursion - time o(n^2) and space - o(n^2)
            // int ans = recursion(sqr,target);
            // return ans-1;
    
            // top down dp - time o(n^2) and space - o(n) + o(n)
            // vector<int> dp(n+3,-1);
            // int ans = top_down_dp(sqr,target,dp);
            // return ans - 1;
    
            // bottom up dp - time o(n^2) and space - o(n) 
            int ans = bottom_up_dp(sqr,target);
            return ans - 1;
        }
    };