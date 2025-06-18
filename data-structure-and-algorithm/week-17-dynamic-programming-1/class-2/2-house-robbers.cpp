// https://leetcode.com/problems/house-robber/
// in DP, DP[i] denotes the maximum amount of money got by robber by the time he reachs to ith home from 0th.

// this is include-exclude pattern. because we are choosing whether to rob the house or not

class Solution {
public:

    int recursion(vector<int>& nums, int curr){
        // if we have only 1 house left, we can steal it
        if (curr == 0)
            return nums[0];
        
        // if house doesn't exist, then we can't steal so it's zero
        if(curr < 0)
            return 0;

        // if we include current house for stealing, then we can't steal n-1 house
        int include_ans = nums[curr] + recursion(nums,curr-2);

        // if we exclude current house for stealing, then we can steal n-1 house
        int exclude_ans = recursion(nums,curr-1);

        return max(include_ans,exclude_ans);

    }

    int top_down_dp(vector<int>& nums,int curr,vector<int>& dp){
        // if we have only 1 house left, we can steal it
        if (curr == 0)
            return nums[0];
        
            // if house doesn't exist, then we can't steal so it's zero
        if(curr < 0)
            return 0;

             // if it has already computed the answer, then get answer from previous result
        if (dp[curr] != -1) return dp[curr];

        // if we rob the current house then , we can't rob next house, we will have to find the ans for n-2
        int include_ans = nums[curr] + top_down_dp(nums,curr-2,dp);

        // if don't rob the current house, then get the answer of robbing o to n-1 houses
        int exclude_ans = top_down_dp(nums,curr-1,dp);

        dp[curr] = max(include_ans,exclude_ans);
        return dp[curr];
    }

    int bottom_up_dp(vector<int>& nums){
        vector<int> dp(nums.size(),-1);

        dp[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            
            int include = nums[i];
            if(i-2 >=0)
                include = nums[i] + dp[i-2];
            
            int exclude = dp[i-1];

            dp[i] = max(include,exclude);
        }

        return dp[nums.size()-1];
    }

    int dp_optimization(vector<int>& nums){
        
        if (nums.size()==0)
            return 0;
        if (nums.size()==1)
            return nums[0];
        
        if (nums.size() == 2)
            return max(nums[0],nums[1]);

        int first = nums[0],second = max(nums[0],nums[1]);

        int ans = 0;
        for(int i=2;i<nums.size();i++){
            
            int include = nums[i];
            if(i-2 >=0)
                include = nums[i] + first;
            
            int exclude = second;

            ans = max(include,exclude);
            first = second;
            second = ans;
        }

        return ans;
    }



    int rob(vector<int>& nums) {
        // recursion // time complexity - exponential
        // return recursion(nums, nums.size()-1);
        
        // -----------

        // top down dp
        // time complexity o(n)
        // space complexity - o(n) (DP array) + o(n) (function call stack)

        // vector<int> dp(nums.size(),-1);
        // return top_down_dp(nums,nums.size()-1,dp);
        // -----------

        // bottom up dp
        // time complexity o(n)
        // space complexity - o(n) (DP array) 

        // return bottom_up_dp(nums);
        // -----------
        
        //do optimization
        // time complexity - o(n)
        // space complexity - o(1)
        return dp_optimization(nums);
    }
};