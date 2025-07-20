https://leetcode.com/problems/jump-game-ii/description/

class Solution {
public:

    int recursion(vector<int>& nums, int curr){
        // recursion
        if (curr == nums.size()-1)
            return 0;
        
        int maximumPossibleJumps = nums[curr];

        //  flag to store the booleans value to check if it reached to end or not
        int minimumJump = INT_MAX;

        for(int jump = 1;jump <= maximumPossibleJumps; jump++){
            
            if(curr+jump < nums.size()){
                int recursion_ans = recursion(nums, curr + jump);
                if(recursion_ans != INT_MAX){
                    minimumJump = min(minimumJump, recursion_ans+1);
                }
            }

        }

        return minimumJump;
    }


    int dp_memoization(vector<int>& nums, int curr, vector<int>& dp){
         // recursion
        if (curr == nums.size()-1)
            return 0;
        
        if(dp[curr] != -1)
            return dp[curr];

        int maximumPossibleJumps = nums[curr];

        //  flag to store the booleans value to check if it reached to end or not
        int minimumJump = INT_MAX;

        for(int jump = 1;jump <= maximumPossibleJumps; jump++){
            
            if(curr+jump < nums.size()){
                int recursion_ans = dp_memoization(nums, curr + jump,dp);
                if(recursion_ans != INT_MAX){
                    minimumJump = min(minimumJump, recursion_ans+1);
                }
            }

        }

        dp[curr] = minimumJump;
        return minimumJump;

    }


    int dp_tabulation(vector<int>& nums){

        vector<int> dp(nums.size()+5,INT_MAX);

        int n=nums.size();

        dp[n-1] = 0;

        for(int curr = n-2 ; curr >= 0; curr--){

            int maximumPossibleJumps = nums[curr];

            //  flag to store the booleans value to check if it reached to end or not
            int minimumJump = INT_MAX;

            for(int jump = 1;jump <= maximumPossibleJumps; jump++){
                if(curr+jump < nums.size()){
                    int recursion_ans = dp[curr + jump];
                    if(recursion_ans != INT_MAX){
                        minimumJump = min(minimumJump, recursion_ans+1);
                    }
                }
            }

            dp[curr] = minimumJump;

        }

        return dp[0];

    }

    int jump(vector<int>& nums) {
        // recursion
        // return recursion(nums,0);

        //--------------------------------
        // memoization
        // vector<int> dp(nums.size()+5,-1);
        // return dp_memoization(nums,0, dp);

        //----------------------
        // tabulation
        return dp_tabulation(nums);


    }
};