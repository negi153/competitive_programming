
// leetcode easy - https://leetcode.com/problems/fibonacci-number/

class Solution {
public:
    int recSolve(int n){ // recursive solution -> time complexity -> exponential
        ///base case
        if(n==1 || n==0)
            return n;
        
        int ans = recSolve(n-1) + recSolve(n-2);

        return ans;
    }

    // top-down approah or "recursion + memoization"
    int topDownDPSolution(int n,vector<int>& dp){
        ///base case
        if(n==1 || n==0)
            return n;
        
        // step 3. check if ans already exist
        if(dp[n] != -1)
            return dp[n];

        // step 2. replace ans with dp[n]
        dp[n] = topDownDPSolution(n-1,dp) + topDownDPSolution(n-2,dp);

        return dp[n];
    }

    // iterative solution or "tabulation method"
    int bottomUpDPSolution(int n){
            /// step1. create dp array
            vector<int> dp(n+1,-1);

            // step2. observe base case in recursion solution
            dp[0]=0;
            if(n==0)
                return dp[0];
                
            dp[1]=1;
            if(n==1)
                return dp[1];

            //step3. iteratively calculate ans
            for(int i=2;i<=n;i++){
                dp[i] = dp[i-1] + dp[i-2];
            }

            return dp[n];
    }


    int spaceOptimizeDpSolution(int n){
            
            if(n==0 || n==1)
                return n;
            int prev2=0;
            int prev1 =1;
            int curr;

            for(int i=2;i<=n;i++){
                curr = prev1 + prev2;
                // shifting
                prev2 = prev1;
                prev1 = curr;
            }

            return curr;
    }


    int fib(int n) {
        // 1. recursive solution --> time--> exponential, space->o(n) 
        // int ans = recSolve(n); 
        // return ans;
        
        //------------------------------------------------
        
        // 2. Dynamic programming solution -> top down solution --> recursion + memoization
        // step 1. creata dp array
        // vector<int> dp(n+1,-1); // since element can be from n to 0, so total number of elements are n+1    --> time -> o(n) , space -> o(2n) (recursive stack + dp array)
        // int ans = topDownDPSolution(n,dp); // recursion + memoization
        // return ans;

        // 3. Dynamic programming -> bottom up solution --> iterative solution || tabulation method --> time--> o(n) , space (dp array)--> o(n)
        // int ans = bottomUpDPSolution(n);
        // return ans;

        //4. Dynamic programming - space optimize solution -> time -> o(n) , space-> o(1)

        int ans = spaceOptimizeDpSolution(n);
        return ans;
        
    }
};