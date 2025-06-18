// https://leetcode.com/problems/number-of-provinces/submissions/1659896964/
// logc - simply count the number of connected components

class Solution {
public:
    void visitDfs(int src, vector<vector<int>>& graph, vector<bool>& visited){

        visited[src] = true;

        for(int nbrIndex = 0;nbrIndex < graph.size();nbrIndex++){
            if(nbrIndex != src && !visited[nbrIndex] && graph[src][nbrIndex]==1){
                visitDfs(nbrIndex,graph,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n+5,false);
        int cnt = 0;

        for(int i=0;i<n;i++){
                if(!visited[i]){
                    visitDfs(i,isConnected,visited);
                    cnt++;
                
            }
        }

        return cnt;
    }
};