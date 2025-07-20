// https://neetcode.io/problems/valid-tree?list=blind75
//logic - graph will be only tree, if - 
            // - if it have only 1 connected componenet
            // - and there should not be a cycle


class Solution {
public:
    // this will check if cycle is present or not
    bool dfs(int currNode, vector<bool>& visited,unordered_map<int,list<int>>& g, int parent){

        visited[currNode] = true;

        for(auto nbr: g[currNode]){
            if(!visited[nbr]){
                bool ans = dfs(nbr,visited,g,currNode);
                if(ans)
                    return true;
            }
            else{
                // if visited already
                if(parent != nbr)
                    return true;
            }
        }

    }

    bool validTree(int n, vector<vector<int>>& edges) {
            // check if cycle is presnebt or not
            unordered_map<int,list<int>> g;
            for(auto x:edges){
                g[x[0]].push_back(x[1]);
                g[x[1]].push_back(x[0]);
            }

            vector<bool> visited(n+5, false);
            int cnt = 0;
            for(int i=0;i<n;i++){
                if(!visited[i]){
                    int parent = -1;
                    cnt++;
                    bool ans = dfs(i,visited,g,parent);
                    if(ans)
                        return false; // cycle exist

                    if(cnt > 1) // if there are more than 1 componenet, then it cant be tree
                        return false;

                }
            }

            return true;
    }
};
