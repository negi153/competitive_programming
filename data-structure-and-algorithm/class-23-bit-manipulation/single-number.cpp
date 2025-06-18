// https://leetcode.com/problems/single-number/

// logic - same number gives 0 when done xor

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for(int i=1;i<nums.size();i++)
            ans = ans ^ nums[i];

        return ans;
    }
};   