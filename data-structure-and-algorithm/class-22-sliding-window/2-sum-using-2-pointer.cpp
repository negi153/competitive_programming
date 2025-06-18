https://leetcode.com/problems/two-sum/
// //logic - put left pointer on 0 and right pointer on n-1, 
//     if sum of left and right elemetn = target, then answer found,
//     if sum of left and right element > target, then right --
//     if sum of left and right element < target, then left++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // create new vector with indexes
        vector<pair<int,int>> newNums;
        for(int i=0;i<nums.size();i++){
            newNums.push_back({nums[i],i});
        }

        sort(newNums.begin(),newNums.end());
        int left =0,right = nums.size()-1;

        vector<int> ans;

        while(left<=right){
            if(newNums[left].first+newNums[right].first == target){
                ans.push_back(newNums[left].second);
                ans.push_back(newNums[right].second);
                break;
            }
            else if (newNums[left].first+newNums[right].first < target)
                left++;
            else
                right--;
        }

        return ans;
    }
};