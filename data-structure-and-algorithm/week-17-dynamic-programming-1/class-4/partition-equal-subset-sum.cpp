// https://leetcode.com/problems/partition-equal-subset-sum/description/
// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.


// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].

//logic - 
    // if total sum is n, so find a partition whose sum will be n/2, if we find that that means there exit two partititon with same sum

    class Solution {
    public:
    
        bool recursion(vector<int>& nums, int curr_index,int target){
            // base case
            if(curr_index < 0){
                return 0;
            }
    
            // if target becomes 0, then there exist a partition
            if(target == 0)
                return 1;
    
            // include the curent element
            bool include_ans = recursion(nums,curr_index-1,target-nums[curr_index]);
    
            // exclude the current element
            bool exclude_ans = recursion(nums,curr_index-1,target);
    
            return include_ans || exclude_ans;
        }
    
        bool top_down(vector<int>& nums, int curr_index,int target,vector<vector<int>>& dp){
            // base case
            if(curr_index < 0){
                return 0;
            }
    
            // if target becomes 0, then there exist a partition
            if(target == 0)
                return 1;
    
            if (dp[curr_index][target] != -1)
                return  dp[curr_index][target];
    
            // include the curent element
            bool include_ans = false;
            if (target-nums[curr_index] >= 0)
                include_ans = top_down(nums,curr_index-1,target-nums[curr_index],dp);
    
            // exclude the current element
            bool exclude_ans = top_down(nums,curr_index-1,target,dp);
    
            dp[curr_index][target] = include_ans || exclude_ans;
    
            return  dp[curr_index][target];
        }
    
        bool bottom_up(vector<int>& nums,int target){
            int n = nums.size();
            vector<vector<int>> dp(n,vector<int>(target+1,0));
    
            // base case handle
            for(int curr_index = 0;curr_index < n;curr_index++)
                dp[curr_index][0] = 1;
    
            for(int curr_index = 1;curr_index < n;curr_index++){
                for(int tg = 1; tg <= target; tg++){
                    
                    // include the curent element
                    bool include_ans = false;
                    if (tg-nums[curr_index] >= 0)
                        include_ans = dp[curr_index-1][tg-nums[curr_index]];
    
                    // exclude the current element
                    bool exclude_ans = dp[curr_index-1][tg];
    
                    dp[curr_index][tg] = include_ans || exclude_ans;
                }
            }
    
            return dp[n-1][target];
        }
    
        bool bottom_up_so(vector<int>& nums,int target){
            int n = nums.size();
            vector<int> prev(target+1,0);
            vector<int> curr(target+1,0) ;
    
            // base case handle
            prev[0]=1;
            curr[0]=1;
    
            for(int curr_index = 1;curr_index < n;curr_index++){
                for(int tg = 1; tg <= target; tg++){
                    
                    // include the curent element
                    bool include_ans = false;
                    if (tg-nums[curr_index] >= 0)
                        include_ans = prev[tg-nums[curr_index]];
    
                    // exclude the current element
                    bool exclude_ans = prev[tg];
    
                    curr[tg] = include_ans || exclude_ans;
                }
    
                // shift
                prev = curr;
            }
    
            return curr[target];
        }
    
        bool bottom_up_so_single(vector<int>& nums,int target){
            int n = nums.size();
            vector<int> curr(target+1,0) ;
    
            // base case handle
            curr[0]=1;
    
            for(int curr_index = n-1;curr_index >=1 ;curr_index--){
                for(int tg = target; tg >= 1 ; tg--){
                    
                    // include the curent element
                    bool include_ans = false;
                    if (tg-nums[curr_index] >= 0)
                        include_ans = curr[tg-nums[curr_index]];
    
                    // exclude the current element
                    bool exclude_ans = curr[tg];
    
                    curr[tg] = include_ans || exclude_ans;
                }
    
            }
    
            return curr[target];
        }
    
        bool canPartition(vector<int>& nums) {
            int total = accumulate(nums.begin(),nums.end(),0);
    
            // if total sum is odd, then we can't partition it into 2 partition
            if (total % 2 == 1)
                return false;
            
            // look for half of the total sum in array, if we found any partition having sum as target, then there exists our answer otherwise no
            int target = total /2;
            int n = nums.size();
    
            int curr_index = n - 1 ;
    
            // recusion. time - o(2^n)
            // return recursion(nums,curr_index,target);
    
            // top down dp , time - o(n*m) , space - o(n*m)
            // vector<vector<int>> dp(n,vector<int>(target+1,-1));
            // return top_down(nums,curr_index,target,dp);
    
            // bottom up dp time. o(n*m), space - o(n*m)
            // return bottom_up(nums,target);
    
            // // bottom up dp with space optimizaation. time - o(n*m), space o(n)
            // return bottom_up_so(nums,target);
    
            // bottom up dp with space optimizaation in single array. time - o(n*m), space o(n)
            return bottom_up_so_single(nums,target);
        }
    };