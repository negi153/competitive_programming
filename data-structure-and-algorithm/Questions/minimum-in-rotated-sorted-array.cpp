// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
// https://neetcode.io/solutions/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int binary_search_1(vector<int>& nums){
        int ans = nums[0];
        int left = 0, right = nums.size()-1;

        while(left <= right){
            int mid = (left + right)/2;

            if(nums[right] >= nums[left]){ // when a sorted array
                ans = min(ans,nums[left]);
            }

            ans = min(ans, nums[mid]);
            if(nums[mid] >= nums[left] ) // if mid element is more than left element, means we are in left partition so we need to check in right partititon
                left = mid+1;
            else // if mide element is less than left element,  means we are in right partition so we need to check left partition
                right = mid-1;
        }

        return ans;
    }

    int findMin(vector<int>& nums) {
        // aproach 1 - sort the aray and find minimum - o(n*logn)
        // approach 2 - iterate one time and find the smallest - o(n)

        // approach 3 - since it's sorted rotated, we need answer in o(logn)
        // [3,4,5,1,2] - 
        return binary_search_1(nums); 
    }
};