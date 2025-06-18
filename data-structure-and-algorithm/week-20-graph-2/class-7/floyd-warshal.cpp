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

    
    void floydWarshal(int n){
        vector<vector<int>> dist(n,vector<int>(n,1e9)); // 10k we have added because, when given INT_MAX, it was going out of bound when addition
        
        // insert 0 in diagonal element -> distance of element from same elelent
        for(int i=0;i<n;i++)
            dist[i][i] = 0;
            
        // insert distance as prewen in graph
        for(auto t:adjList){
            for(auto nbr:t.second){
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second;
                dist[u][v] = wt;
            }
        }
        
        // get distance using helper function
        for(int helper = 0;helper<n;helper++){
            for(int src=0;src<n;src++){
                for(int dest=0;dest<n;dest++){
                    dist[src][dest] = min(dist[src][dest],dist[src][helper] + dist[helper][dest]);
                }
            }
        }
        
        cout<<"Distance of every node from other node using floyd warshal - "<<endl;
        for(auto x:dist){
            for(auto y: x)
                cout<<y<<" ";
            
            cout<<endl;
        }
    }

};

int main (){

    graph g;

    g.addEdge(0,1,3,1);
    g.addEdge(0,3,5,1);
    g.addEdge(1,0,2,1);
    g.addEdge(1,3,4,1);
    g.addEdge(2,1,1,1);
    g.addEdge(3,2,2,1);
    
    // g.addEdge(0,1,5,1);
    // g.addEdge(0,2,6,1);
    // g.addEdge(2,1,-3,1);

    g.printGraph();
    int n= 4;
    g.floydWarshal(n);
    
    return 0;
}