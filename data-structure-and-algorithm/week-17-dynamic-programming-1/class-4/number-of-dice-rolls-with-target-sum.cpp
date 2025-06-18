class Solution {
    public:
        int MOD = 1000000007;
    
        int recursion(int n,int k, int target){
            // baase cases
    
            // we don't have dice and also we don't have target, then it's a way
            if(n < 0)
                return 0;
    
            if (n == 0 && target == 0)
                return 1;
            
            // if we on't have dice but we have target position or negative, then not valid
            if (n == 0 && target != 0)
                return 0;
            
            // if we have dice but we don't have target, then not valid
            if (n > 0 && target <= 0)
                return 0;
    
    
            int ans = 0;
            for(int face = 1;face<=k; face++){
                // if we use face, then find the other from recursion
                ans = ans + recursion(n-1,k,target-face);
            }
    
            return ans;
        }
    
        int top_down_dp(int n, int k, int target, vector<vector<int>>& dp){
            // baase cases
    
            if (n<0)
                return 0;
                
            // we don't have dice and also we don't have target, then it's a way
            if (n == 0 && target == 0)
                return 1;
            
            // if we on't have dice but we have target position or negative, then not valid
            if (n == 0 && target != 0)
                return 0;
            
            // if we have dice but we don't have target, then not valid
            if (n > 0 && target <= 0)
                return 0;
    
            if (dp[n][target] != -1)
                return dp[n][target];
    
            // find different ways 
            int ans = 0;
            for(int face = 1;face<=k; face++){
                // if we use face, then find the other from recursion
                ans = (ans + top_down_dp(n-1,k,target-face,dp))%MOD;
            }
            dp[n][target] = ans;
    
            return dp[n][target];
        }
    
        int bottom_up_dp(int n, int k, int target){
    
            vector<vector<int>> dp(n+1,vector<int>(target+1,0));
    
            dp[0][0] = 1;
            
            for(int i=1; i<=n; i++){
                for(int tg=0; tg<=target; tg++){
                
                    // find different ways 
                    int ans = 0;
                    for(int face = 1;face<=k; face++){
                        // if we use face, then find the other from recursion
                        if(tg-face >= 0)
                            ans = (ans + dp[i-1][tg-face])%MOD;
                    }
                    dp[i][tg] = ans;
                    
                }
            }
    
            return dp[n][target];
        }
    
        int bottom_up_dp_so(int n, int k, int target){
            vector<int> prev(target+1,0);
            vector<int> curr(target+1,0);
    
            prev[0] = 1;
            
            for(int i=1; i<=n; i++){
                for(int tg=0; tg<=target; tg++){
                
                    // find different ways 
                    int ans = 0;
                    for(int face = 1;face<=k; face++){
                        // if we use face, then find the other from recursion
                        if(tg-face >= 0)
                            ans = (ans + prev[tg-face])%MOD;
                    }
                    curr[tg] = ans;
                    
                }
                // shift --> yahan mai galti krunga
                prev = curr;
            }
    
            return curr[target];
        }
    
        int bottom_up_dp_so_single(int n, int k, int target){
            // using single array
            vector<int> curr(target+1,0);
    
            curr[0] = 1;
            
            // here we have reversed our loopp, because if we will go from o->n, 0->target, so we are updating the old valuesl which we need for later 
            // so if we are going from right to left, n->0, target->0, so we will not overwirte previous value
            for(int i=n; i>=1; i--){
                for(int tg=target; tg>=0; tg--){
                
                    // find different ways 
                    int ans = 0;
                    for(int face = 1;face<=k; face++){
                        // if we use face, then find the other from recursion
                        if(tg-face >= 0)
                            ans = (ans + curr[tg-face])%MOD;
                    }
                    curr[tg] = ans;
                    
                }
            }
    
            return curr[target];
        }
    
        int numRollsToTarget(int n, int k, int target) {
    
            // recursion - time - 
            // return recursion(n,k,target);
    
            // top down dp - time - time o(n*target*k), space o(n*target) + o(n*target*k) (recursive stack)
            // vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
            // return top_down_dp(n,k,target,dp);
        
            // bottom up dp - time o(n*target*k), space o(n*target)
            // return bottom_up_dp(n,k,target);
    
            // bottom up dp space optimization with 2 array - time o(n*target*k), space o(target) (using 2 array)
            // return bottom_up_dp_so(n,k,target);
    
            // bottom up dp space optimization with single array  - time o(n*target*k), space o(target) (using 1 array)
            return bottom_up_dp_so_single(n,k,target);
    
        }
    };