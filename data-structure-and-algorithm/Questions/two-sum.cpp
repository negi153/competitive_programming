https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum1(vector<int>& nums, int target) { // 2 pointer - nlogn
        // time - n*logn
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


    vector<int> twoSum(vector<int>& nums, int target) { // map - o(n)
        unordered_map<int,int> mp ; // visited element with their index

        for(int i=0;i<nums.size();i++){
            int required_num = target - nums[i];

            if(mp.find(required_num) != mp.end())
                return {mp[required_num],i};
            
            mp[nums[i]] = i;
        }

        return {};
    }
};