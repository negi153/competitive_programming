/*

leetcode medium - https://leetcode.com/problems/coin-change/

*/

class Solution {
public:

    int rec(vector<int>& coins, int amount){
        // recursion
        // time complexity - for every amount, it's making recursive call equal to the total number of coins. so it's exponential

    
        if (amount < 0)
            return INT_MAX;

        if (amount == 0)
            return 0;
        
        int mini = INT_MAX;

        for( int i = 0 ; i< coins.size(); i++){
            int ans = rec(coins, amount - coins[i]);

            if (ans != INT_MAX)
                mini = min(mini, ans + 1);
        }

        return mini;
    }

    int top_down(vector<int>& coins, int amount, vector<int>& dp){
        // botton up approach or memoization
        // time complexity - for every amount, it's calculating only 1 time, so time - O(amount)
        // space complexity - recursion stack space - o(n) + dp space o(n)

        if (amount < 0)
            return INT_MAX;

        if (amount == 0)
            return 0;
        
        // check in dp array
        if(dp[amount] != -1)
            return dp[amount];

        int mini = INT_MAX;

        for( int i = 0 ; i< coins.size(); i++){
            int ans = top_down(coins, amount - coins[i], dp);

            if (ans != INT_MAX)
                mini = min(mini, ans + 1);
        }

        dp[amount] = mini;
        return mini;
    }


    int bottom_up(vector<int>& coins, int amount){
        // bottom up dynamic programming or tabulation method

        // time complexity - for every amount, it's calculating only 1 time, so time - O(amount)
        // space complexity -  dp space o(n)

        vector<int> dp(amount + 1, INT_MAX); // since dp array shows the minimum number of coins needs to make an amount, so we will default the element with INT_MAX

        // we can make amount 0 by using 0 coins
        dp[0] = 0;

        // find answer for every amount from 1 to amount
        for(int target = 1; target <= amount; target++){

            int mini = INT_MAX;

            for( int i = 0 ; i< coins.size(); i++){
                if (target - coins[i] >= 0){
                    int ans = dp[target - coins[i]];

                    if (ans != INT_MAX)
                        mini = min(mini, ans + 1);

                }
                
            }

            dp[target] = mini;
            
        }

        // return the minimum number of coins used to create a amount
        return dp[amount];

    }

    int coinChange(vector<int>& coins, int amount) {
        // recursion
        // int ans = rec(coins, amount);
        // if (ans == INT_MAX)
        //     return -1;
        // else
        //     return ans;

        //----------------------------------------

        // top down approach or memoization
        // vector<int> dp(amount + 1, -1); 
        // int ans = top_down(coins, amount, dp);
        // if(ans != INT_MAX)
        //     return ans;
        // else
        //     return -1;

        //----------------------------------------

        // bottom up approach or tabulation

        int ans = bottom_up(coins, amount);
        if(ans != INT_MAX)
            return ans;
        else
            return -1;



    }
};