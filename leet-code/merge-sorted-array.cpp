// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.


class Solution {
public:
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) { // brute force -> o(nlogn)
        for(int i=0;i<n;i++){
            nums1[m+i]=nums2[i];
        }   

        sort(nums1.begin(),nums1.end());
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) { // optimise -> time -> o(n+m) // two pointers approach
        vector<int> ans;
        int i=0,j=0;

        while(i<m || j<n){

            if(i==m){
                ans.push_back(nums2[j]);
                j++;
            } 
            else if(j==n){
                ans.push_back(nums1[i]);
                i++;
            }
            else if(nums2[j]<=nums1[i]){
                ans.push_back(nums2[j]);
                j++;
            }    
            else if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
        }

        for(int i=0;i< (m+n);i++){
            nums1[i]=ans[i];
        }


    }
};