// https://leetcode.com/problems/maximum-subarray/description/

// Kadane's algorithm
// time complexity - o(n)
// we can also initialise maxSum = nums[0], if there is atleast 1 elemetn

class Solution {
public:
    // this is kadane's algorithm
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, maxSum = INT_MIN;

        for(auto x: nums){
            currSum += x;
            maxSum = max(maxSum,currSum);

            if(currSum < 0)
                currSum = 0;
        }

        return maxSum;
    }
};


/// brute force - o(n^2) - get sum of every possible subarray and find the maximum
// divide and conquer - o(n* logn)
    // logic - 
        // divide array from middle
        // find the answer from left subary, right subarray and combining left and right subarray
            // how to find answer in combining left and right subarray
            // from the middle go to right side and find the maximum sum subarray
            // from the middle go to left and find the minimum  sum subarray
            // add those
        // return the maximum
// kadane's algorithm - o(n)