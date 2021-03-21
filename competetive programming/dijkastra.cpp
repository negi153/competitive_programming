#include<bits/stdc++.h>

using namespace std;

#define SIZE 100000+1


// single source shortest path problem-->shortest path of every node from single source
//dijkastra algorithm is used to find the shortest path and distance of every node from source node.
// it works on graphs where weight is mentioned.if graph has no weight then use BFS to find the shortest path 
// and distance  of every node from source node.
// it can be used for directed as well as for undirected graph.
// it fails for the graph in which negative weight edges are present.
// for some  graphs (containing negative weight edges) it will give the correct answer but for some graphs
// it will fail.
// it cannot find the negative weight cycles in the graph

vector<pair<int,int> > v[SIZE];//each vertex has all the connected vertices with the edges weight
int dis[SIZE];
bool vis[SIZE];
int parent[SIZE];


void dijkstra(int n){//n is no. of nodes

for(int i=0;i<SIZE;i++)//set all vertices distance as infinity
    dis[i]=2e5;

dis[0]=0;//set distance of source from surce 0
memset(vis,false,sizeof(vis));//set all vertex as unvisited
memset(parent,-1,sizeof(parent));//set parent of every node as -1

multiset< pair<int,int> > s;//it is same a min-priority queue
s.insert({0,0});//insert distance of source as 0 {distance,source node}

while(!s.empty()){

    pair<int,int> p=*s.begin();//first take vertex with minimum distance;star is here to convert iterator into pair
    s.erase(s.begin());

    int x=p.second;

    vis[x]=true;

    for(int i=0;i<v[x].size();i++){ //for every adjacent node e we are finding whether there can 
        // be a shorter path if we go through node x from source s
        int e=v[x][i].first;
        int w=v[x][i].second;

        if(vis[e]==false and dis[x]+w<dis[e]){
            dis[e]=dis[x]+w;//check if the next vertex distance could be minimized
            parent[e]=x; //set parent of a node
            s.insert({dis[e],e});//insert the next vertex with the updated distance
        }
    }

}

//showing distance of all nodes from source node 1
cout<<"shortest distance of every node from source node :\n";

for(int i=0;i<n;i++)
    cout<<"0 - "<<i<<" => "<<dis[i]<<endl;

}



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


int main(){

#ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
#endif

int s,m,n,from,next,weight;
// cout<<"enter no. of nodes and no. of edges : ";
cin>>n>>m;
// cout<<"enter edges from ,next and weight : ";

bool directed=false;

for(int i=0;i<m;i++){
    cin>>from>>next>>weight;
    v[from].push_back({next,weight});

    if(directed==false)
        v[next].push_back({from,weight});
}

dijkstra(n);

//show the shortest path of  node from source node

show_path(4);

return 0;
}
