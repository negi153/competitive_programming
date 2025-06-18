// https://leetcode.com/problems/subsets/submissions/1650851432/

// Given an integer array nums of unique elements, return all possible subsets
// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

class Solution {
    public:
    
        void recursion(vector<int>& nums, int index, vector<vector<int>>& result, vector<int> subset){
            if ( index < 0){
                result.push_back(subset);
                return;
            }
    
            // exclude
            recursion(nums,index-1,result,subset);
    
            // include
            subset.push_back(nums[index]);
            recursion(nums,index-1,result,subset);
    
        }
    
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> result;
            vector<int> subset;
            recursion(nums,nums.size()-1,result,subset);
    
            return result;
        }
    };