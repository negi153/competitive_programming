
// Median of Two Sorted Arrays
// Hard
// 22.1K
// 2.5K
// Companies
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

 

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.

// https://www.youtube.com/watch?v=NTop3VTjmxk
class Solution {
public:
    //brute force approach, time 
     double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
         // Brute Force:
               // 1.Merge Both Array
              // 2.Sort them
             // 3.Find Median
            // TIME COMPLEXITY: O(n)+O((n+m)log(n+m))+O(m)
            // SPACE COMPLEXITY: O(n+m)

         // Initialization some neccessary variables
        vector<int>v;
        
        // store the array in the new array
        for(auto num:nums1)   // O(n1)
            v.push_back(num);
        
        for(auto num:nums2)  // O(n2)
            v.push_back(num);
        
        // Sort the array to find the median
        sort(v.begin(),v.end());  // O(nlogn)
        
        // Find the median and Return it
        int n=v.size();  // O(n)
        
        return n%2?v[n/2]:(v[n/2-1]+v[n/2])/2.0;
    }


    // 2 pointers approach  --> time o(n+m), space --> o(n+m)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int k=n+m;

        vector<int> merge;
        int i=0,j=0;

        while(i<n || j<m){
            // cout<<i<<" "<<j<<" -> ";
            if(j==m){
                // cout<<"add "<<nums1[i]<<endl;
                merge.push_back(nums1[i]);
                i++;
            }
            else if(i==n){
                // cout<<"add "<<nums2[j]<<endl;
                merge.push_back(nums2[j]);
                j++;

            }
            else if(nums1[i]<=nums2[j]){
                merge.push_back(nums1[i]);
                // cout<<"add "<<nums1[i]<<endl;
                i++;
            }
            else if(nums2[j]<nums1[i]){
                // cout<<"add "<<nums2[j]<<endl;
                merge.push_back(nums2[j]);
                j++;

            }

            
        }
        
        if(k%2==1) 
            return merge[k/2];
        else 
            return (merge[k/2 - 1] + merge[k/2])/2.0;
    }

};