https://leetcode.com/problems/course-schedule-ii/
// similar to couse schedule, just we need to send the order of topological elemsnts


class Solution {
public:

    vector<int> topoSortBfs(int n, unordered_map<int,list<int>>& adjList)
    {
        // khan's algorightm - to detect cycle in directed graph
        vector<int> indegree(n,0);
        // get the indegree of all the nodes
        for(int i=0;i<n;i++){
            for(auto nbr:adjList[i]){
                indegree[nbr]++;
            }
        }

        vector<int> topo; // vector to store topological sort elements

        queue<int> q;
        // add all the nodes with indegree in queue
        for(int i=0;i<n;i++)
            if(indegree[i]==0)
                q.push(i);

        while(!q.empty()){
            int front = q.front();
            q.pop();

            topo.push_back(front);

            for(auto nbr:adjList[front]){
                indegree[nbr]--;

                if(indegree[nbr]==0)
                    q.push(nbr);                    
                }
        }

        if(topo.size()==n)
            {
                // no cycle
                return topo;
            }
        else{
            // cycle is present
            return {};
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adjList;
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adjList[v].push_back(u);
        }

        return topoSortBfs(numCourses,adjList);

    }
};