https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int i=0,j=0;
        long long int s = 0;

        while(j<nums.size()){
            s = s + nums[j];

            // remove from left
            while(s >= target){
                ans = min(ans,j-i+1);
                s = s - nums[i];
                i++;
            }
            j++;
        }

        if (ans==INT_MAX)
        return 0;

        return ans;
    }
};