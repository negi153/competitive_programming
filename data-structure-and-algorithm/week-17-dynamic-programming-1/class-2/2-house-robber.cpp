// https://leetcode.com/problems/house-robber/
// in DP, DP[i] denotes the maximum amount of money got by robber by the time he reachs to ith home from 0th.


class Solution {
public:

    int solveUsingRecursive(vector<int>& nums, int n)
    {
        // if house doesn't exist, then we can't steal so it's zero
        if(n < 0)
            return 0;

        // if we have only 1 house left, we can steal it
        if(n == 0)
            return nums[0];

        // if we include current house for stealing, then we can't steal n-1 house
        int include = nums[n] + solveUsingRecursive(nums,  n-2);

        // if we exclude current house for stealing, then we can steal n-1 house
        int exclude = solveUsingRecursive(nums,  n-1);

        return max(include, exclude);

    }

    int solveUsingTopDown(vector<int>& nums, int n, vector<int>& dp)
    {   
        // Top down dynamic programing or Memoization
        
        // if house doesn't exist, then we can't steal so it's zero
        if(n < 0)
            return 0;

        // if we have only 1 house left, we can steal it
        if(n == 0)
            return nums[0];

        // if it has already computed the answer, then get answer from previous result
        if(dp[n] != -1)
            return dp[n];

        // if we include current house for stealing, then we can't steal n-1 house
        int include = nums[n] + solveUsingTopDown(nums,  n-2, dp);

        // if we exclude current house for stealing, then we can steal n-1 house
        int exclude = solveUsingTopDown(nums,  n-1, dp);

        dp[n] = max(include, exclude); 
        return dp[n];

    }


    int solveUsingBottomUp(vector<int>& nums, int n)
    {   
        // Bottom UP dynamic programing or Tabulation
        
        // create dp array
        vector<int> dp(n+1,-1);

        // provide base case
        dp[0] = nums[0];

        // loop
        for(int i = 1; i <= n; i++){

            if (i-1 >= 0)
                dp[i] = max(dp[i], dp[i-1]);


            if(i-2 >= 0)
                dp[i] = max(dp[i], dp[i-2] + nums[i]);
            else
                dp[i] = max(dp[i], nums[i]) ;
                
        }

        return dp[n];

    }

    int solveSpaceOptimize(vector<int>& nums, int n)
    {   
        // Bottom UP dynamic programing with space optimized
        // prev2 -> prev1 -> current

        // base case
        int prev2 = 0;
        int prev1 = nums[0]; 

        int cur_profit = 0;

        // loop
        for(int i = 1; i <= n; i++){
            // exclude
            int exclude = max(cur_profit, prev1);

            //include
            int include = max(cur_profit, prev2 + nums[i]) ;

            cur_profit = max(include, exclude);

            // update first_from_left with second_from_left
            prev2 = prev1;

            // update second_from_left with cur_profit
            prev1 = cur_profit;
                
        }

        return prev1;

    }


    int rob(vector<int>& nums) {
        // recursion - 
        // time complexity - exponential
        
        // int n = nums.size() - 1; // index of last house
        // return solveUsingRecursive(nums, n);

        //--------------------------
        // top down Dynamic programing or Memoization - 
        // time complexity o(n)
        // space complexity - o(n) (DP array) + o(n) (function call stack)

        // int n = nums.size() - 1; // index of last house
        // vector<int> dp(n + 1, -1); // initialize dp array with -1, since we need to find the maximum amount
        
        // return solveUsingTopDown(nums, n, dp);        

        //---------------------------------
        // bottom up approach or tabulation method  - 
        // time complexity o(n)
        // space complexity - o(n) (DP array) 

        // int n = nums.size() - 1; // index of last house
        // return solveUsingBottomUp(nums, n);

        //----------------------------------------------
        // space optimized dynamic programming
        // time complexity - o(n)
        // space complexity - o(1)
        
        int n = nums.size() - 1; // index of last house
        return solveSpaceOptimize(nums,n);

    }
};