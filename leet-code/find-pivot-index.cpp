// Given an array of integers nums, calculate the pivot index of this array.

// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

// Return the leftmost pivot index. If no such index exists, return -1.

 

// Example 1:

// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11


class Solution {
public:
    int pivotIndex1(vector<int>& nums) {  // brute force approach - time -> o(n^2), space-> o(1)
        for(int i=0;i<nums.size();i++){ // pick i element as answer and find the left and right sum for that element.
            int ls=0,rs=0;
            for(int j=0;j<i;j++) ls+=nums[j];
            for(int j=i+1;j<nums.size();j++) rs+=nums[j];

            // cout<<i<<" "<<ls<<" "<<rs<<endl;

            if(ls==rs) {
                return i;
            }
        }

        return -1;
    }

    int pivotIndex2(vector<int>& nums) {  // time optimize --> time -> o(n), space-> o(2*n)
        // store prefix sum and suffix sum in seperate vector.
        int n= nums.size();
        vector<int> ls(n,0),rs(n,0);
        
        ls[0]=nums[0];  // store prefix sum in a new vector
        for(int i=1;i<n;i++){
            ls[i] = ls[i-1] + nums[i];
        }
        
        // store suffix sum in new vector
        rs[n-1] = nums[n-1];
        for(int j=n-2;j>=0;j--){
            rs[j] = rs[j+1] + nums[j];
        }

        // for each index find the left and right sum and find the index
        for(int i=0;i<nums.size();i++){
            
            int left_sum = 0;
            if(i!=0)
                left_sum = ls[i-1];

            
            int right_sum = 0;
            if(i!=n-1)
                right_sum = rs[i+1];

            if(left_sum==right_sum)
                return i;
        
        }

        return -1;
    }

    int pivotIndex3(vector<int>& nums) { // space optimize --> time ->o(n), space-> o(n)
        // create only prefix sum vector and find the index
        int n= nums.size();
        vector<int> ls(n,0);
        
        // create prefix sum vector
        ls[0]=nums[0];
        for(int i=1;i<n;i++){
            ls[i] = ls[i-1] + nums[i];
        }
        
        // compare left and right side sum
        for(int i=0;i<nums.size();i++){
            
            int left_sum = 0;
            if(i!=0)
                left_sum = ls[i-1];

            
            int right_sum = 0;
            if(i!=n-1)
                right_sum = ls[n-1]-ls[i];

            if(left_sum==right_sum)
                return i;
        
        }

        return -1;
    }

    int pivotIndex(vector<int>& nums) { // space optimize --> time ->o(n), space-> o(1)
        int n= nums.size();
        
        // crate prefix sum in same vector as initial
        for(int i=1;i<n;i++)
            nums[i] += nums[i-1];
        
        for(int i=0;i<n;i++){
            
            int left_sum = 0;
            if(i!=0)
                left_sum = nums[i-1];

            int right_sum = 0;
            if(i!=n-1)
                right_sum = nums[n-1]-nums[i];

            if(left_sum==right_sum)
                return i;
        
        }

        return -1;
    }
};