https://leetcode.com/problems/longest-increasing-subsequence/
// this is based on LIS (longest increasing subsequence)
// this question has n = 10^5, so even with bottom up dp space optimization, time complexity will be o(n^2). which will not pass all the test cases.
// so apply dp with binary search for LIS here.
// logic -> 
//     1. sort according to width in increasing order and hight in descreasing order if width of 2 envelopes are same
//     2. apply the LIS with binary search in the heights of envelopes to the the logest increasing subsequence 

class Solution {
    public:
    
        int recursion(vector<vector<int>>& nums, int curr, int prev){
            
            int n = nums.size();
            if(curr >= n)
                return 0; // since it's outside the range, so can't get any longest incressing subsequence from here
    
            // include in subsequence based on the condition
            int include_ans = 0;
            if(prev == -1 || (nums[curr][0] > nums[prev][0] && nums[curr][1] > nums[prev][1]))
                include_ans = 1 + recursion(nums,curr+1,curr); // since we included the current, then previous will be equal to current
    
            // exclude in subsequence
            int exclude_ans = recursion(nums,curr+1,prev);
    
            int ans = max(include_ans, exclude_ans);
            return ans;
        }
    
        int top_down_dp(vector<vector<int>>& nums, int curr, int prev, vector<vector<int>> & dp){
            
            int n = nums.size();
            if(curr >= n)
                return 0; // since it's outside the range, so can't get any longest incressing subsequence from here
    
            if (dp[curr][prev+1] != -1)
                return dp[curr][prev+1];
    
            // include in subsequence based on the condition
            int include_ans = 0;
            if(prev == -1 || (nums[curr][0] > nums[prev][0] && nums[curr][1] > nums[prev][1]))
                include_ans = 1 + top_down_dp(nums,curr+1,curr,dp); // since we included the current, then previous will be equal to current
    
            // exclude in subsequence
            int exclude_ans = top_down_dp(nums,curr+1,prev,dp);
    
            dp[curr][prev+1] = max(include_ans, exclude_ans);
            return dp[curr][prev+1];
        }
    
        int bottom_up_dp(vector<vector<int>>& nums){
            int n = nums.size();
            
            vector<vector<int>> dp(n+2,vector<int>(n+2,0)) ;
    
            // curr o to n, prev = -1 to n
            for(int curr = n-1;curr >= 0; curr--){
                for(int prev = curr-1;prev >=-1; prev--){
                    
                    int include_ans = 0;
                    if(prev == -1 || (nums[curr][0] > nums[prev][0] && nums[curr][1] > nums[prev][1]))
                        include_ans = 1 + dp[curr+1][curr+1];
    
                    int exclude_ans = dp[curr+1][prev+1];
    
                    dp[curr][prev+1] = max(include_ans, exclude_ans);
    
                }
            }
    
            return dp[0][0];
        }
    
        int bottom_up_dp_so(vector<vector<int>>& nums){
            int n = nums.size();
            
            vector<int> curRow(n+2,0);
            vector<int> nextRow(n+2,0);
            
            // curr o to n, prev = -1 to n
            for(int curr = n-1;curr >= 0; curr--){
                for(int prev = curr-1;prev >=-1; prev--){
                    
                    int include_ans = 0;
                    if(prev == -1 || (nums[curr][0] > nums[prev][0] && nums[curr][1] > nums[prev][1]))
                        include_ans = 1 + nextRow[curr+1];
    
                    int exclude_ans = nextRow[prev+1];
    
                    curRow[prev+1] = max(include_ans, exclude_ans);
    
                }
                nextRow = curRow;
            }
    
            return curRow[0];
        }
    
        int envelope_binary_search(vector<vector<int>>& ans,vector<int>& envelop ){
            int left = 0, right = ans.size()-1;
    
            int mid,ind = -1;
            while(left <= right){
                mid = left + (right - left)/2;
    
                if(envelop[0] <= ans[mid][0] and envelop[1] <= ans[mid][1])
                    {
                        ind = mid;
                        right = mid-1;
                    }
                else
                    left = mid+1;
            }
    
            return ind;
    
        }
    
        static bool comp(vector<int>& a, vector<int>& b){
            if(a[0]==b[0])
                return a[1] > b[1];
            
            return a[0] < b[0];
        }
    
        int dp_binary_search(vector<vector<int>>& nums){
            sort(nums.begin(),nums.end(),comp);
    
            int n = nums.size();
            vector<int> ans;
            ans.push_back(nums[0][1]);
    
            for(int i = 1;i<nums.size();i++){
                if(nums[i][1] > ans.back())
                    ans.push_back(nums[i][1]);
                else{
                    // find the number in answer which is just higher than the nums[i]
                    int index = lower_bound(ans.begin(),ans.end(),nums[i][1]) - ans.begin();
                    ans[index] = nums[i][1]; // update the number with nums[i]
                }
            }
    
            return ans.size();
            
        }
    
        int maxEnvelopes(vector<vector<int>>& envelopes) {
            // sort(envelopes.begin(),envelopes.end());
    
            // recursion,  time out o(n^2)
            int curr = 0,prev = -1;
            // return recursion(envelopes,curr,prev);
    
            // top down dp,  time out o(n^2)
            // vector<vector<int>> dp(envelopes.size()+2,vector<int>(envelopes.size()+2,-1));
            // return top_down_dp(envelopes,curr,prev,dp);
    
            // bottom up dp - here we got memory limit exceeded,  time out o(n^2)
            // return bottom_up_dp(envelopes);
    
            // bottom up dp space optimized - time out o(n^2)
            //    return bottom_up_dp_so(envelopes);
    
            // dynamic programming with binrary search
            return dp_binary_search(envelopes);
    
        }
    };