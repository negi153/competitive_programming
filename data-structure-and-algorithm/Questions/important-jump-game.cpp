// https://leetcode.com/problems/jump-game/description/

class Solution {
public:

    bool recursion(vector<int>& nums, int curr){
        // recursion

        if (curr == nums.size()-1)
            return true;
        
        if (curr >= nums.size())
            return false;

        int maximumPossibleJumps = nums[curr];

        //  flag to store the booleans value to check if it reached to end or not
        bool reachingFlag = false;

        for(int jump = 1;jump <= maximumPossibleJumps; jump++){

            reachingFlag = reachingFlag || recursion(nums, curr + jump);

        }

        return reachingFlag;
    }


    bool dp_memoization(vector<int>& nums, int curr, vector<int>& dp){
        // dynamic programming memoization

        if (curr == nums.size()-1)
            return true;
        
        if (curr >= nums.size())
            return false;

        if (dp[curr] != -1)
            return dp[curr];

        int maximumPossibleJumps = nums[curr];

        //  flag to store the booleans value to check if it reached to end or not
        bool reachingFlag = false;

        for(int jump = 1;jump <= maximumPossibleJumps; jump++){

            reachingFlag = reachingFlag || dp_memoization(nums,curr + jump, dp);

        }

        dp[curr] = reachingFlag;

        return reachingFlag;

    }


    bool dp_tabulation(vector<int>& nums){

        vector<bool> dp(nums.size(),false);

        int n=nums.size();

        dp[n-1] = true;

        for(int curr = n-2 ; curr >= 0; curr--){

            int maximumPossibleJumps = nums[curr];

            //  flag to store the booleans value to check if it reached to end or not
            bool reachingFlag = false;

            for(int jump = 1;jump <= maximumPossibleJumps; jump++){
                if(curr + jump < n)
                    reachingFlag = reachingFlag || dp[curr + jump];

            }

            dp[curr] = reachingFlag;

        }

        return dp[0];

    }

    bool canJump(vector<int>& nums) {
        // recursion
        // return recursion(nums,0);

        //--------------------------------
        // memoization
        // vector<int> dp(nums.size(),-1);
        // return dp_memoization(nums,0, dp);

        //----------------------
        // tabulation
        // return dp_tabulation(nums);


        // optimize greedy - o(n)
        // here we will go from right to left and shift the goal post.
        // initially our goal post is at n-1 index, go in loop from n-2 to 0.
        // if current_index + jumps is greater than or equal to the index of goal post, that means we can reach goal post from current index. so shift the goal post to current index.
        // if at the end , our goal post is at index 0, then it means we can reach last index from 0th index.

        int n = nums.size();
        int goalPostIndex = n-1;

        for(int i = n-2; i >= 0; i--){
            if(i + nums[i] >= goalPostIndex){
                goalPostIndex = i; // shift the goal post to left side
            }
        }

        if(goalPostIndex == 0)
            return true;
        else
            return false;

    }
};