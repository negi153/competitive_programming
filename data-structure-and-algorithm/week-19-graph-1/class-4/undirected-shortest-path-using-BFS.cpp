#include<iostream>
#include<stack>
#include<unordered_map>
#include<list>
#include<vector>
#include<limits.h>
#include<set>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

class graph{
    public:
    unordered_map<int,list<pair<int,int>>> adjList;

    void addEdge(int u,int v, int wt, int direction){
        adjList[u].push_back({v,wt});
        
        if(direction == 0){
            // undirected graph
            adjList[v].push_back({u,wt});
        }
    }

    void printGraph(){
        cout<<"Graph - "<<endl;
        for(auto node:adjList){
            cout<<node.first<<"->";
            for(auto dest:node.second){
                cout<<"("<<dest.first<<","<<dest.second<<"), ";
            }
            cout<<endl;
        }
    }

    void shortestPathUsingBfs(int src, int dest){
        queue<int> q;
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        // apply bfs to find the parent of each node
        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto nbr:adjList[front]){
                int nbr_node = nbr.first;
                if(!visited[nbr_node]){
                    q.push(nbr_node);
                    visited[nbr_node] = true;
                    parent[nbr_node] = front;
                }
            }
        }

        // get the shortes path from destination to source
        vector<int> path;
        int node = dest;
        while(node != -1){
            path.push_back(node);
            node = parent[node];
        }

        // after this the path will be in reverse order
        reverse(path.begin(),path.end());

        cout<<"Shortest path is : ";
        for(auto i:path)
            cout<<i<<" ";

        cout<<endl;
    }

};

int main(){

    graph g;
    g.addEdge(0,1,1,0);
    g.addEdge(1,2,1,0);
    g.addEdge(2,3,1,0);

    g.addEdge(3,4,1,0);
    g.addEdge(0,5,1,0);
    g.addEdge(5,4,1,0);
    
    g.addEdge(0,6,1,0);
    g.addEdge(6,7,1,0);
    g.addEdge(7,8,1,0);
    g.addEdge(8,4,1,0);

    g.printGraph();

    int src = 0, dest = 4;
    g.shortestPathUsingBfs(src,dest);

    return 0;

}