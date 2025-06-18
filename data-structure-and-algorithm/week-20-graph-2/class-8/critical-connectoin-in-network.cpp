https://leetcode.com/problems/critical-connections-in-a-network/
// this will be solved by getting the bridge edges using tarjan's algorithm.

class Solution {
public:

    void findBridges(int src,int parent,int& timer, vector<int>& tin,vector<int>& low,unordered_map<int,bool>& vis,vector<vector<int>>& ans, unordered_map<int,list<int>>& adjList){

        vis[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;
        
        for(auto nbr: adjList[src]){

            if(nbr == parent)
                continue;

            if(!vis[nbr]){
                //dfs call
                findBridges(nbr,src,timer,tin,low,vis,ans,adjList);

                // low update
                low[src] = min(low[src],low[nbr]);

                if(low[nbr] > tin[src]){
                    // cout<<nbr<<"--"<<src<<" is a bridge"<<endl;
                    vector<int> temp = {src,nbr};
                    ans.push_back(temp);
                }

            }
            else{ // visited but not parent, so update low. means there is another way
                low[src]  = min(low[src],low[nbr]);
            }

        }


    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // create graph
        unordered_map<int,list<int>> adjList;
        for(int i = 0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        // apply tarjan's algorithm
        vector<vector<int>> ans;

        int timer = 1;
        vector<int> tin(n);
        vector<int> low(n);
        unordered_map<int,bool> vis;
        
        findBridges(0,-1,timer,tin,low,vis,ans,adjList);

        return ans;
    }
};