
// https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/
//logic - greedy
    // 1. sort the cost in ascending
    // 2. put a pointer on right most index.
    // 3. include this (n-1) and previous of this(n-2) to amount
    // 4. skip n-3. 

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();

        if(n==1)
            return cost[0];
        if(n==2)
            return cost[0] + cost[1];

        // sort candies
        sort(cost.begin(),cost.end());

        int buyIndex = n-1;
        int amt = 0;
        while(buyIndex >= 0){
            amt += cost[buyIndex];
            buyIndex--;

            if(buyIndex >= 0){
                amt += cost[buyIndex];
                buyIndex--;
            }

            buyIndex--;
                            
        }

        return amt;
    }
};