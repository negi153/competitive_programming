// https://www.geeksforgeeks.org/problems/painting-the-fence3727/1

#include <iostream>
#include<vector>
using namespace std;

//
  // for n = 0, since there are no fence so answer will be 0,
  // for n = 1, since only 1 fence, then it can be coloured by k ways
  // for n = 2, XX, since there are 2 fence and k colour, by permutation and combinatin, it can be coloured by k*k ways.
  // for n = 3, either the last 2 can be same or different
              // XRR - if last 2 are same, then by recursion get the  the different ways from 0 to 1.
                  // whateer value comes from f(1) multiply with (k-1), because, we can't have painted with k colours becaause it will be same colour three time
                  // f(3) = f(1) * (k-1)
              // XXR - f(3) = f(2) * (k-1). by recursion get the answer for f(n-1), and we will have only k-1 ways to colour

              // f(n) = f(n-1) * (k-1) + f(n-2) * (k-1)
              //       = (f(n-1) + f(n-2)) * (k-1)

//

int solveUsingRecursion(int n, int k) {
  if(n == 1) {
    return k ;
  }
  if(n == 2) {
    return (k + k*(k-1));
  }

  int ans  = (solveUsingRecursion(n-2,k) + solveUsingRecursion(n-1,k))*(k-1);
  return ans;
}

int solveUsingMem(int n, int k, vector<int>& dp)  {
    if(n == 1) {
    return k ;
  }
  if(n == 2) {
    return (k + k*(k-1));
  }

  if(dp[n] != -1)
    return dp[n];

  dp[n]  = (solveUsingMem(n-2,k,dp) + solveUsingMem(n-1,k,dp))*(k-1);
  return dp[n];
}

int solveUsingTab(int n, int k)  {
  vector<int> dp(n+1, 0);
  dp[1] = k;
  dp[2] = (k + k*(k-1));

  for(int i=3; i<=n; i++) {

    dp[i]  = (dp[i-2] + dp[i-1])*(k-1);
    
  }
  return dp[n];
}

int solveSO(int n, int k ) {
  
  int prev2 = k;
  int prev1 = (k + k*(k-1));

  for(int i=3; i<=n; i++) {

    int curr  = (prev2 + prev1)*(k-1);

    //shhift -> yaha hi galti karunga ya karungi 
    prev2 = prev1;
    prev1 = curr;
    
  }
  return prev1;
  
}



int main() {

  int n = 4;
  int k = 3;

  // int ans = solveUsingRecursion(n, k);


  // vector<int> dp(n+1, -1);
  // int ans = solveUsingMem(n, k,dp);

  int ans = solveSO(n,k);
  cout << "ans: " << ans << endl;
  




  return 0;
}