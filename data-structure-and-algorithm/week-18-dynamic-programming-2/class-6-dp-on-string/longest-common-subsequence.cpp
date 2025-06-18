// https://leetcode.com/problems/longest-common-subsequence/

// very important question - 
// logic - compare first element of both the string, if both matches, then we got 1 length and remaining recursion will take care 1 to n1, 1 to 21. if first eelent of both the string doesn't match then answer will be maximum of recursive answeer max(ans[2 to n1, 1 to n1], ans[1 to n1, 2 to n2])

class Solution {
    public:
        int lcs_recursion(string text1,string text2, int i,int j ){
            
            // if no element is ramaining in text1, then can't find common 
            if(i == text1.length())
                return 0;
            
            // if no element is ramaining in text1, then can't find common 
            if(j == text2.length())
                return 0;
    
            if(text1[i] == text2[j])
                return 1 + lcs_recursion(text1,text2,i+1,j+1);
            else
                return max(lcs_recursion(text1,text2,i+1,j), lcs_recursion(text1,text2,i,j+1));
    
        }
    
        int lcs_top_down_dp(string& text1,string& text2, int i,int j,vector<vector<int>>& dp ){
            
            // if no element is ramaining in text1, then can't find common 
            if(i == text1.length())
                return 0;
            
            // if no element is ramaining in text1, then can't find common 
            if(j == text2.length())
                return 0;
    
            if (dp[i][j] != -1)
                return dp[i][j];
    
            if(text1[i] == text2[j])
                dp[i][j] =  1 + lcs_top_down_dp(text1,text2,i+1,j+1,dp);
            else
                dp[i][j] =  max(lcs_top_down_dp(text1,text2,i+1,j,dp), lcs_top_down_dp(text1,text2,i,j+1,dp));
    
            return dp[i][j];
    
        }
    
       int lcs_bottom_up_dp(string text1,string text2 ){
            int n1 = text1.length(), n2 = text2.length();
    
            vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    
            for(int i=n1-1;i>=0;i--){
                for(int j=n2-1;j>=0;j--){
                    
                    if(text1[i] == text2[j])
                        dp[i][j] =  1 + dp[i+1][j+1];
                    else
                        dp[i][j] =  max(dp[i+1][j], dp[i][j+1]);
                }
            }
                    
            return dp[0][0];
    
        }
    
        int longestCommonSubsequence(string text1, string text2) {
            int i = 0,j=0;
    
            // recursion
            // return lcs_recursion(text1,text2,i,j);
    
            // top down dp
            // vector<vector<int>> dp(text1.length(),vector<int>(text2.length(),-1));
            // return lcs_top_down_dp(text1,text2,i,j,dp);
    
            // bottom up dp
            return lcs_bottom_up_dp(text1,text2);
    
        }
    };