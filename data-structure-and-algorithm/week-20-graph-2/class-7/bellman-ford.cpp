#include<iostream>
#include<stack>
#include<unordered_map>
#include<list>
#include<vector>
#include<limits.h>
#include<set>

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

    
    void bellmanFordAlgo(int n, int src){
        vector<int> dist(n,INT_MAX);
        
        // initialise distance of source node to 0
        dist[0] = 0;
        
        // apply relaxation n-1 times
        for(int i=1;i<= n-1;i++){
            
             // apply relaxation on each edge
             for(auto t:adjList){
                 for(auto nbr: t.second){
                     int u = t.first;
                     int v = nbr.first;
                     int w = nbr.second;
                     
                     // relaxation
                     if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                         dist[v] = dist[u] + w;
                     }
                 }
             }
        }
        
        for(int i=0;i<n;i++){
            cout<<"distance of "<<i<<" from "<<src<<" : "<<dist[i]<<endl;
        }
    }

};

int main (){

    graph g;

    g.addEdge(0,1,-1,1);
    g.addEdge(0,2,4,1);
    g.addEdge(1,2,3,1);
    g.addEdge(1,3,2,1);
    g.addEdge(1,4,2,1);
    g.addEdge(3,1,1,1);
    g.addEdge(3,2,5,1);
    g.addEdge(4,3,-3,1);
    
    
    // g.addEdge(0,1,5,1);
    // g.addEdge(0,2,6,1);
    // g.addEdge(2,1,-3,1);

    g.printGraph();
    
     int n=5,src = 0;
    g.bellmanFordAlgo(n,src);
    return 0;
}