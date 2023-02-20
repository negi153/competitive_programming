// Two Sum
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1]

class Solution {
public:
    vector<int> twoSum1(vector<int>& nums, int target) { //basic approach-> o(n^2) , space -> o(1)
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }


    vector<int> twoSum2(vector<int>& nums, int target) {  // using hashmap
    // time o(n), space o(2*n)
        map<int,vector<int> > mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]].push_back(i);

        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int second_number = target - nums[i];

            if(mp.find(second_number) != mp.end()){
                for(auto x : mp[second_number]){
                    if(x!=i){
                        ans.push_back(i);
                        ans.push_back(x);
                        return ans;
                    }
                }
            }
            
        }

        return ans;
        
    }

    // easy by hashmap
    vector<int> twoSum3(vector<int>& nums, int target) { 
        // time o(n), space-> o(n)
        vector<int> ans;
        unordered_map<int,int> visited;

        for(int i=0;i<nums.size();i++){
            int number = nums[i];
            int complement_number = target-number;

            if(visited.count(complement_number)) // if element is present in visited hashmap
                {
                    ans.push_back(i);
                    ans.push_back(visited[complement_number]);
                    return ans;
                }
            else
                visited[number]=i;

        }
        return ans;
    }

    //hashmap , time - o(n), space - o(n)
    vector<int> twoSum4(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(target - nums[i]) == mp.end())
                mp[nums[i]] = i;
            else
                return {mp[target - nums[i]], i};
        }
 
        return {-1, -1};
    }

    //sorting
    vector<int> twoSum5(vector<int>& nums, int target) {
        // time -> soritng - o(nlogn), space-> o(n)        
        // create a vector with single element as -> (element, index)
        //sort the vector on the basis of element.
        //iterate on each element of the above vector and check if target-current_element exist in vector or not by binary search
        // if target-current_element exist then return the index of current_element & target-current_element.

    }

    //sorting, 2 pointers approach
    vector<int> twoSum5(vector<int>& nums, int target) {
        // time -> soritng - o(nlogn), space-> o(n)        
        // create a vector with single element as -> (element, index)
        //sort the vector on the basis of element.
        
        // put left pointer at 0 index and right pointer at n-1 index in sorted array,
        // if arr[left] + arr[right] > target, then right-- // shift right pointer to left side to decrease the sum
        // else if  arr[left] + arr[right] < target, then left++ // shift left pointer to right side to increase the sum
        // else arr[left] + arr[right] == target, then return their indexes
        // follow above process until left<right

    }
};