// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/

//logic - find the answer for each partition. for each partition, there will be a tree, find answer from each partition and then return the  minimum



class Solution {
    public:
    
        int smallest_sum_recursion(vector<int>& arr,int left,int right, map<pair<int,int>,int>& maxi){
            
            // when left and right both are at the same location, that means it is leaf node
            // and we don't need leaf node in our answer. as we only need sum of non-leaf node
            if(left == right)
                return 0;
    
            int smallest_ans = INT_MAX;
    
            // for each partitoin, find the smallest_sum
            for(int i = left; i<=right;i++){
                // when we are i, then left part -> left to i 
                                    // and right part -> i+1 to right
                
                int rec_ans = smallest_sum_recursion(arr,left,i,maxi) + smallest_sum_recursion(arr,i+1,right,maxi);
                // since this is non-leaf node, we need this node in our ans
                int ans = (maxi[{left,i}] * maxi[{i+1,right}]) + rec_ans;
    
                smallest_ans = min(smallest_ans,ans);
            }
    
            return smallest_ans;
    
        }
    
        int smallest_sum_top_down(vector<int>& arr,int left,int right, map<pair<int,int>,int>& maxi,vector<vector<int>>& dp){
            
            // when left and right both are at the same location, that means it is leaf node
            // and we don't need leaf node in our answer. as we only need sum of non-leaf node
            if(left == right)
                return 0;
    
            if(left > right)
                return 0;
    
            if (dp[left][right] != -1)
                return dp[left][right];
    
            int smallest_ans = INT_MAX;
    
            // for each partitoin, find the smallest_sum
            for(int i = left; i<right;i++){
                // when we are i, then left part -> left to i 
                                    // and right part -> i+1 to right
                
                int rec_ans = smallest_sum_top_down(arr,left,i,maxi,dp) + smallest_sum_top_down(arr,i+1,right,maxi,dp);
                // since this is non-leaf node, we need this node in our ans
                int ans = (maxi[{left,i}] * maxi[{i+1,right}]) + rec_ans;
    
                smallest_ans = min(smallest_ans,ans);
            }
    
            dp[left][right] = smallest_ans;
            return dp[left][right];
    
        }
    
        int smallest_sum_bottom_up(vector<int>& arr,map<pair<int,int>,int>& maxi){
            int n = arr.size();
            vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
            for(int left = n-1; left >= 0;left --){
                
                for(int right = 0; right < n; right ++){
                    
                    if (left >= right)
                        continue;
    
                    int smallest_ans = INT_MAX;
    
                    // for each partitoin, find the smallest_sum
                    for(int i = left; i<right;i++){
                        // when we are i, then left part -> left to i 
                                            // and right part -> i+1 to right
                        
                        int rec_ans = dp[left][i] + dp[i+1][right];
    
                        // since this is non-leaf node, we need this node in our ans
                        int ans = (maxi[{left,i}] * maxi[{i+1,right}]) + rec_ans;
    
                        smallest_ans = min(smallest_ans,ans);
                    }
    
                    dp[left][right] = smallest_ans;
                    
                }
    
            }
    
            return dp[0][n-1];
    
        }
    
        int mctFromLeafValues(vector<int>& arr) {
            map<pair<int,int>,int> maxi;
            int n = arr.size();
            
            // create map which stores maximum number between a range.
            for(int i = 0;i<n;i++){
                maxi[{i,i}] = arr[i];
                for(int j=i+1;j<n;j++){
                    maxi[{i,j}] = max(maxi[{i,j-1}], arr[j]);
                }
            }
            
    
            // recursion
            int left = 0,right=n-1;
            // int ans = smallest_sum_recursion(arr,left,right,maxi);
            // return ans;
    
            // top down dp
            // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
            // int ans = smallest_sum_top_down(arr,left,right,maxi,dp);
            // return ans;
    
            // bottom up
            int ans = smallest_sum_bottom_up(arr,maxi);
            return ans;
    
        }
    };