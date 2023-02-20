// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

class Solution {
public:
    
    bool containsDuplicate1(vector<int>& nums) { //BRUTE FORCE time-> o(n^2)    
//     Make nested loop , generate all possible pair
// Put a condition if both of the number generate in a pair are same
// In this approach only the unique pair will be formed becouse outerloop is running from 0 to n - 1, and inner loop will start from one value extra from previous loop value ( which make it to run n*(n+1)/2 ) . if we are matching each and every pair of vector , then possibly we can compare if any of them have same value then return true. else at end of nested form loop return false.

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j])
                    return true;
            }
        }

        return false;    
    }


    // solution with sorting -> time o(nlogn)
    bool containsDuplicate2(vector<int>& nums) {
//         sort the array.
// linearly traverse , find if there is any of the number and its greater one are equal or not

        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1])
                return true;
        }

        return false;
    }

    // solution with set -> time o(nlogn)
    bool containsDuplicate3(vector<int>& nums) {
        //         Set only don't contain duplicate elment .

        // If the size of set if less than the original vector then it contain duplicate element.

        // For your set approach, time complexity can be reduced from O(nlogn) to O(n) using an unordered_set. Regular set uses trees with O(logn) insert, but unordered_sets use hashing for O(1). :)

    set<int> s(nums.begin(),nums.end());

    if(nums.size()>s.size())
        return true;
    else
        return false;

    }


    // solution with hashmap
    bool containsDuplicate(vector<int>& nums) {
//         traverse vector and count frequency using any data structure.
// Iterate through data structure to find if the frequency is beyond 1.

        map<int,int> mp;
        for(auto i : nums) mp[i]++;
        bool flag = false;
        for(auto i : mp){
            if(i.second >= 2) return true;
        }
        return flag;

    }
};
