// this is kosaraju algorithm to find the number of strongly connected component in graph

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
    
    void topoDfs(int src,stack<int>& s, unordered_map<int,bool>& visited){
        
        visited[src] = true;
        
        for(auto nbr:adjList[src]){
            if(!visited[nbr]) 
                topoDfs(nbr,s,visited);
        }
        
        s.push(src);// add element in topo stack
    }

    void Dfs(int src, unordered_map<int,bool>& visited, unordered_map<int,list<int>>& adjNew){
        
        visited[src] = true;
        cout<<src<<" ";
        
        for(auto nbr:adjNew[src]){
            if(!visited[nbr]) 
                Dfs(nbr,visited,adjNew);
        }
    }
    
    
    void countSCC(int n){
        // count strongly connected component
        
        // step 1. find the topological order
        stack<int> s;
        unordered_map<int,bool> visited;
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                topoDfs(i,s,visited);
            }
        }
        
        // step 2. Reverse the edges and create a new graph
        unordered_map<int,list<int>> adjNew;
        for(auto t:adjList){
            for(auto nbr: t.second){
                int u = t.first;
                int v = nbr;
                
                adjNew[v].push_back(u);
            }
        }
         
        // step 3. traverse and count by iterating in topo order
        int count = 0;
        unordered_map<int,bool> visited2;
        while(!s.empty()){ // get the top element from stack which will follow topological order
            int node = s.top();
            s.pop();
            
            if(!visited2[node]){
                cout<<"Below is strongly connected component number - "<<count+1<<endl;
                Dfs(node,visited2,adjNew);
                count++;
                cout<<endl;
            }
        }
         
         
        cout<<"strongly connectedd component count - "<<count<<endl;
    }
    
    

};

int main (){

    graph g;

    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,0,1);
    g.addEdge(2,4,1);
    g.addEdge(4,5,1);
    g.addEdge(5,6,1);
    g.addEdge(6,4,1);
    g.addEdge(6,7,1);
    
    g.printGraph();
    
    int n= 8;
    g.countSCC(8); // count the strongly connected component

    return 0;
}