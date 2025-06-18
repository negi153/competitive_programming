// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
// Examples:

// Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
// Output: true 
// Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.

class Solution {
    public:
    
      bool isSubsetSumRec(vector<int>& arr, int index, int sum, vector<vector<int>>& dp){
          // base case
          if (sum == 0)
              return 1;
          if (index < 0)
              return 0;
          
          if (dp[index][sum] != -1)
              return dp[index][sum];
              
          // include
          if(arr[index]>sum)
              dp[index][sum] = isSubsetSumRec(arr,index-1, sum,dp);
          else 
              dp[index][sum] = isSubsetSumRec(arr,index-1, sum,dp) || isSubsetSumRec(arr,index-1, sum-arr[index],dp);
          
      
          return dp[index][sum];
      } 
      
  
  // Function to initiate the subset sum check
  bool isSubsetSum(vector<int>&arr, int sum) {
     int n = arr.size();
  
      vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
      return isSubsetSumRec(arr, n-1, sum, dp);
  }
  
  };