// https://leetcode.com/problems/jump-game-iii/
// logic - since we can only jump to curr + arr[curr] or curr - arr[curr]. so we will apply dfs here to check if we can reach to the element 0 or not

class Solution {
public:

    bool dfs(vector<int>& arr,int curr, vector<bool>& visited){
        
        if(arr[curr] == 0)
            return true;

        visited[curr] = true;

        bool ans = false;

        if(curr+arr[curr] < arr.size() && !visited[curr+arr[curr]])
            ans = ans || dfs(arr, curr+arr[curr], visited);
        
        if(curr-arr[curr] >= 0 && !visited[curr-arr[curr]])
            ans = ans || dfs(arr, curr-arr[curr], visited); 

        return ans;
    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size()+5,false);
        return dfs(arr,start,visited);
    }
};