// based on LIS
https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/

class Solution {
    public:
        bool is_current_bigger_than_previous(vector<int>& currCuboid, vector<int>& prevCuboid){
            if(currCuboid[0] >= prevCuboid[0] && currCuboid[1] >= prevCuboid[1] && currCuboid[2] >= prevCuboid[2])
                return true;
            else
                return false;
        }
    
        int get_longest_increasing_subsequence(vector<vector<int>>& arr, int curr, int prev,vector<vector<int>>& dp){
    
            if(curr >= arr.size())
                return 0;
    
            if (dp[curr][prev+1] != -1)
                return dp[curr][prev+1];
    
            // include
            int include_ans = 0;
            if(prev == -1 || is_current_bigger_than_previous(arr[curr],arr[prev]) == true)
                include_ans = arr[curr][2] + get_longest_increasing_subsequence(arr,curr+1,curr,dp); // adding current height if we can include
    
            // exclude
            int exclude_ans = get_longest_increasing_subsequence(arr,curr+1,prev,dp);
    
            dp[curr][prev+1] = max(include_ans,exclude_ans);
    
            // cout<<"curr - "<<curr<<", prev - " <<prev+1<<", result - "<<dp[curr][prev+1]<<endl;
            return dp[curr][prev+1];
        }
    
        int get_longest_increasing_subsequence_tabulation(vector<vector<int>>& arr){
            
            int n = arr.size();
            vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    
            for(int curr = n-1; curr >= 0; curr--)
            {
                for(int prev = n-2; prev >= -1; prev--){
                    
                    // include
                    int include_ans = 0;
                    if(prev == -1 || is_current_bigger_than_previous(arr[curr],arr[prev]) == true)
                        include_ans = arr[curr][2] + dp[curr+1][curr+1]; // adding current height if we can include
    
                    // exclude
                    int exclude_ans = dp[curr+1][prev+1];
    
                    dp[curr][prev+1] = max(include_ans,exclude_ans);
                }
            }
    
            // cout<<"curr - "<<curr<<", prev - " <<prev+1<<", result - "<<dp[curr][prev+1]<<endl;
            return dp[0][0];
        }
    
        int get_longest_increasing_subsequence_tabulation_so(vector<vector<int>>& arr){
            
            int n = arr.size();
            // vector<vector<int>> dp(n+2,vector<int>(n+2,0));
            vector<int> currRow(n+2,0);
            vector<int> nextRow(n+2,0);
    
            for(int curr = n-1; curr >= 0; curr--)
            {
                for(int prev = n-2; prev >= -1; prev--){
                    
                    // include
                    int include_ans = 0;
                    if(prev == -1 || is_current_bigger_than_previous(arr[curr],arr[prev]) == true)
                        include_ans = arr[curr][2] + nextRow[curr+1]; // adding current height if we can include
    
                    // exclude
                    int exclude_ans = nextRow[prev+1];
    
                    currRow[prev+1] = max(include_ans,exclude_ans);
                }
                nextRow = currRow;
            }
    
            // cout<<"curr - "<<curr<<", prev - " <<prev+1<<", result - "<<dp[curr][prev+1]<<endl;
            return currRow[0];
        }
    
        int maxHeight(vector<vector<int>>& cuboids) {
    
            // sort each cuboid by height as question said that we can rotate the cuboid and we want maximum height so last element of each cuboid will be height        
    
            for(auto &a: cuboids)
                sort(a.begin(),a.end());
    
            // now to apply longest increasing subsequence we need sorted array
            sort(cuboids.begin(),cuboids.end()); // by default it will be sorted by the first element of each inner array
    
            // implemente lis using top down - time n^2, space - n^2
            // int curr=0,prev = -1; // indexes of current and previos element
            // int n = cuboids.size();
            // vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
            // int ans = get_longest_increasing_subsequence(cuboids,curr,prev,dp);
    
            // return ans;
    
            // implement LIS using bottom up  time n^2, space - n^2
            // int ans = get_longest_increasing_subsequence_tabulation(cuboids);
            // return ans;
    
            // implement LIS using bottom up space optimizatoin  time n^2, space - n
            // int ans = get_longest_increasing_subsequence_tabulation_so(cuboids);
            // return ans;
    
    
    };