// https://leetcode.com/problems/course-schedule/
// logic - check if topological sort exist or not. if it exists that means there is not cycle and we can complete the task otherwise false

class Solution {
public:

    bool topoSortBfs(int n, unordered_map<int,list<int>>& adjList)
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

        return (topo.size() == n);
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adjList;
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adjList[v].push_back(u);
        }

        bool ans = topoSortBfs(numCourses,adjList);

        return ans;

    }
};