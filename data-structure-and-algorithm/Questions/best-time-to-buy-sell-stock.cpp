// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit_1(vector<int>& prices) {
        // time - o(n), space - o(n)
        // create a suffix array which will store the maximum prices till right (except current) at any index
        vector<int> suffixMaxPrice(prices.size(),-1);
        for(int curr = prices.size()-2;curr>=0; curr--){
            suffixMaxPrice[curr] = max(suffixMaxPrice[curr + 1], prices[curr + 1]); 
        }

        // find max profit
        int maxProfit = 0;
        for(int i=0;i<prices.size();i++){
            maxProfit = max(maxProfit, suffixMaxPrice[i] - prices[i]);
        }

        return maxProfit;
    }

    int maxProfit(vector<int>& prices) {
        // time - o(n), space = o(1)
        // logic - if the right prices is higher than left price, then update the maxProfit
        // if right price is lower than left price, then it's negative profit, so update left to new small value which is right
        int left = 0, right = 1;
        int maxProfit = 0;

        while(right < prices.size()){
            if(prices[left] < prices[right]){
                maxProfit = max(maxProfit, prices[right] - prices[left]);
            }
            else{
                // when price of left is more than right, it will be a negative profit
                left = right;
            }
            right++;
        }

        return maxProfit;
    }
};