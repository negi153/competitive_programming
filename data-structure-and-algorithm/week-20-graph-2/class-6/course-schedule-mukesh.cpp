// https://leetcode.com/problems/course-schedule/
//logic - check in directed graph if cycle is present or  not. if cycle is presnet then false other wise true



class Solution {
public:

    bool cycleDfs(unordered_map<int,list<int>>& g, int curr, unordered_map<int,bool>& visited, unordered_map<int,bool>& dfsCalls){

        // cout<<curr<<" "<<endl;
        visited[curr] = true;
        dfsCalls[curr] = true;

        // neighbours
        for(auto nbr: g[curr]){
            if(!visited[nbr]){
                bool ans = cycleDfs(g,nbr,visited,dfsCalls);
                if(ans)
                    return true;
            }
            else{
                if(dfsCalls[nbr])
                    return true; // cycle exist
            }
        }
        

        dfsCalls[curr] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // create graph using map
        unordered_map<int,list<int>> g;
        for(auto edge: prerequisites){
            g[edge[1]].push_back(edge[0]); // to take course 0, first take course 1 means there is an edge from 1->0
        }

        // apply topological sort logic 
        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfsCalls;

        // find cycle detection in directed graph
        bool isCycle = false;
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                isCycle = cycleDfs(g,i,visited,dfsCalls);
                // cout<<i<<" "<<isCycle<<endl;
                if(isCycle)
                    break;
            }
        }

        if(isCycle)
            return false;
        else
            return true;
        
    }
};