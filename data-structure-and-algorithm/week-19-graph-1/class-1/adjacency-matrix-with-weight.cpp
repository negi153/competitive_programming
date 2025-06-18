#include <iostream>
#include<vector>
using namespace std;

    
int main() {
    
    int n,e;
    cout<<"Ener number of nodes and edges : ";
    cin>>n>>e;
    
    vector<vector<int>> graph(n,vector<int>(n,0));
    
    for(int i=0;i<e;i++){
        int u,v,w;
        cout<<"Enter edge and weight : "<<endl;
        cin>>u>>v>>w;
        
        graph[u][v] = w;
        //graph[v][u] = 1; // if graph is undirected then open this comment
    }
    
    cout<<"printing graph : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}