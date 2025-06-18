// this is tarjan's algorithm to find the number of bridges

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
    unordered_map<int,list<int>> adjList;

    void addEdge(int u,int v, int direction){
        adjList[u].push_back(v);
        
        if(direction == 0){
            // undirected graph
            adjList[v].push_back(u);
        }
    }

    void printGraph(){
        cout<<"Graph - "<<endl;
        for(auto node:adjList){
            cout<<node.first<<"->";
            for(auto dest:node.second){
                cout<<dest<<" ";
            }
            cout<<endl;
        }
    }
    
    void findBridges(int src,int parent,int& timer, vector<int>& tin,vector<int>& low,unordered_map<int,bool>& vis){

    vis[src] = true;
    tin[src] = timer;
    low[src] = timer;
    timer++;
    
    for(auto nbr: adjList[src]){

        if(nbr == parent)
            continue;

        if(!vis[nbr]){
            //dfs call
            findBridges(nbr,src,timer,tin,low,vis);

            // low update
            low[src] = min(low[src],low[nbr]);

            if(low[nbr] > tin[src]){
                cout<<nbr<<"--"<<src<<" is a bridge"<<endl;
            }

        }
        else{ // visited but not parent, so update low. means there is another way
            low[src]  = min(low[src],low[nbr]);
        }

    }


}
    

};

int main (){

    graph g;

    g.addEdge(0,1,0);
    g.addEdge(0,2,0);
    g.addEdge(1,2,0);
    g.addEdge(0,3,0);
    g.addEdge(3,4,0);
    
    g.printGraph();
    
    int n=5;
    int timer = 0;
    vector<int> tin(n);
    vector<int> low(n);
    unordered_map<int,bool> vis;
    g.findBridges(0,-1,timer,tin,low,vis);

    return 0;
}