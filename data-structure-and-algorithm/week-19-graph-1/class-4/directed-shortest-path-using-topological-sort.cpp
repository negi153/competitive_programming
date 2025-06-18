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

    void topological_sort(int src, stack<int>& topo, unordered_map<int,bool>& visited){
        visited[src] = true;

        for(auto nbr:adjList[src]){
            if(!visited[nbr.first]){
                topological_sort(nbr.first,topo,visited);
            }
        }

        topo.push(src);
    }

    void shortestPath(int src, int dest){
        unordered_map<int,bool> visited;
        stack<int> topo;
        
        // store topoligical sort in stack
        topological_sort(src,topo,visited);
        
        vector<int> dist(topo.size(),INT_MAX);

        src = topo.top();
        dist[src] = 0;

        while(!topo.empty()){
            int topElement = topo.top();
            topo.pop();
            
            if(dist[topElement] != INT_MAX ){
                for(auto nbr: adjList[topElement]){
                    if(dist[topElement]+ nbr.second < dist[nbr.first])
                        dist[nbr.first] = dist[topElement] + nbr.second;
                }
            }
        }

        cout<<"Shortest path from "<<src<<" to every node is : \n";
        for(int i = 0;i<dist.size();i++)
            cout<<i<<" "<<dist[i]<<" "<<endl;

    }

};

int main(){

    graph g;
    g.addEdge(0,1,5,1);
    g.addEdge(0,2,3,1);
    g.addEdge(2,1,2,1);

    g.addEdge(1,3,3,1);
    g.addEdge(2,3,5,1);
    g.addEdge(2,4,6,1);
    g.addEdge(4,3,1,1);

    g.printGraph();

    int src = 0, dest = 4;
    g.shortestPath(src,dest);

    return 0;

}