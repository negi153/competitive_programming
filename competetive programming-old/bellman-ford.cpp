#include<bits/stdc++.h>

// single source shortest path problem-->shortest path of every node from single source
//works on directed and undirected graph
// it also works same as dijkastra algorithm.it finds minimum distaance of every other vertes from source vertex.
// slower than dijkastra
// advantages-->
// 1. when weights of edges is negative.
// 2. it also find the negative weight cycles in the graph.
// idea of algorithm-->
// 1. go through all the edges of the graph one by one in random order. then apply relaxation on every edge
// 2. do step 1 n-1 time.then we will get the parent of every node and also distance of every node from source
// to check the negative weight cycle do the step 1, one more time. if the distance reduces for any node then
// that means there is negative weight cycle in graph.

 // time complexity-->o(V*E)
 // space compltexity->o(V)
// this algo can be used to find "all source shortest path"-->reapeat bellman ford algo by taking
// all nodes as source one by one-->time o(V^2 * E) ...in worst case E can be V^2 so total time
// compltexity is o(V^4).
// floyd warshell is faster than this....it finds the "all source shortest path" in o(V^3)
using namespace std;
#define SIZE 100000+1

vector<int> v[SIZE];
int dis[SIZE];
int parent[SIZE];

void show_path(int node){
// this function will show the shortest path of a node  from source 
    // node and also distance from sourcr

cout<<"distance of node "<<node<<" from source is : "<<dis[node]<<endl;

vector<int> shortest_path;

//from the current node, add the parent to the vector(going in reverse order). then reverse the 
// vector to find the shortest path
int temp_node=node;

while(node != -1){
    
    shortest_path.push_back(node);
    node=parent[node];

}


cout<<"shortest path of node "<<temp_node<<" from source node : ";

reverse(shortest_path.begin(),shortest_path.end());

for(int i : shortest_path)
    cout<<i<<"->";

}



void bellman(int n,int m,int s){
    int u,r,w;

for(int i=0;i<n;i++){
    dis[i]=2e9;
}

memset(parent,-1,sizeof(parent));

dis[s]=0;

for(int i=0;i<n-1;i++){

    for(int j=0;j<2*m;j++){
            u=v[j][0];
            r=v[j][1];
            w=v[j][2];

            if(dis[u]+w<dis[r]){
                dis[r]=dis[u]+w;
                parent[r]=u;
            }
    }
}

cout<<"minimum distance of all nodes from source node :"<<s<<endl;

for(int i=0;i<n;i++){
    if(i!=s){
        cout<<i<<" "<<dis[i]<<endl;
    }
}

        

}

int main(){

#ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
#endif


int s,m,n,from,next,weight;
// cout<<"enter no. of nodes and no. of edges : ";
cin>>n>>m;
// cout<<"enter edges from ,next and weight : ";
for(int i=0;i<2*m;i+=2){
    cin>>from>>next>>weight;
    v[i].push_back(from);
    v[i].push_back(next);
    v[i].push_back(weight);

    v[i+1].push_back(next);
    v[i+1].push_back(from);
    v[i+1].push_back(weight);
}

s=0;

bellman(n,m,s);

show_path(8);

return 0;
}
