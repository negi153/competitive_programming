// https://leetcode.com/problems/counting-bits/description/

class Solution {
public:
    // vector<int> countBits(int n) {
    //     // this is n* logn solution
    //     vector<int> ans;

    //     for(int i=0;i<=n;i++){
    //         int cnt =0;
    //         int num = i;
    //         while(num){
    //             num = num & ( num-1); // it will remove the right most set bit
    //             cnt++;
    //         }

    //         ans.push_back(cnt);
    //     }
    //     return ans;
    // }

    vector<int> countBits(int n) {
        // this is using dynamidc programming and it's o(n)
        vector<int> dp(n+1,0);

        int highestPowerOf2TillNow = 1;
        for(int i=1;i<=n;i++) {
            if(highestPowerOf2TillNow * 2 == i)
                highestPowerOf2TillNow = i;

            dp[i] = 1 + dp[i - highestPowerOf2TillNow];
        }

        return dp;
    }   
};