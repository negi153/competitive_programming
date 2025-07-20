// https://leetcode.com/problems/3sum/description/

class Solution {
public:

    vector<vector<int>> threeSum_1(vector<int>& nums) {
        // not optimal, it can be optimize
        set<vector<int>> ans;
        int n= nums.size();

        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            int num1 = nums[i];
            int target = 0 - num1;

            int left = i+1, right = n-1;
            while(left < right){
                int curr_sum = nums[left] + nums[right];
                if(curr_sum == target){
                    ans.insert({num1,nums[left],nums[right]});
                    left++;
                    right--;
                }
                else if(curr_sum < target)
                    left++;
                else
                    right--;
            }
        }

        vector<vector<int>> result(ans.begin(),ans.end());
        return result;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for(int i=0;i<n;i++){
            // first numbeer is nums[i]

            if(i > 0 && nums[i] == nums[i-1]) // if my current index is more than 0, then check with previous. because if current is same as previous, it's going to give the duplicate results
                continue;

            // use 2 pointer to solve 2 sum
            int left = i+1, right = n-1; // left is second element index and right is third element index
            while(left < right){
                
                int three_sum = nums[i] + nums[left] + nums[right];
                if(three_sum > 0)
                    right --;
                else if(three_sum < 0)
                    left++;
                else{ // three_sum == 0
                    ans.push_back({nums[i],nums[left],nums[right]}); // since vector is in sorted order

                    // it is possible that we can have multiple left and right with same values
                    // [-2 , -2, 0 , 0, 2, 2] , if we will find the 2 sum here so we will get [-2,2] & [2,2] which are duplicate and we want to remove it. so update the left pointer in forward directtion untill it is same than previous

                    left++;
                    while(nums[left] == nums[left-1] and left < right)
                        left++;
                }
            }
        }

        return ans;
    }
};