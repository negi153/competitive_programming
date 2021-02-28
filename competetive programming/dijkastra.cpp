#include<iostream>
#include<vector>
#include<string.h>//for memset function
#include<set>//for multiset
#include<utility>//for pair

using namespace std;

#define SIZE 100000+1
vector<pair<int,int> > v[SIZE];//each vertex has all the connected vertices with the edges weight
int dis[SIZE];
bool vis[SIZE];

void dijkstra(int n){//n is no. of nodes

for(int i=0;i<SIZE;i++)//set all vertices distance as infinity
    dis[i]=2e5;
dis[1]=0;//set distance of source from surce 0
memset(vis,false,sizeof(vis));//set all vertex as unvisited

multiset< pair<int,int> > s;//it is same a min-priority queue
s.insert({0,1});//insert distance of source as 0 {distance,source node}

while(!s.empty()){

    pair<int,int> p=*s.begin();//first take vertex with minimum distance;star is here to convert iterator into pair
    s.erase(s.begin());

    int x=p.second;
    int w=p.first;

    if(vis[x])
        continue;//check if popped vertex is visited before

    vis[x]=true;

    for(int i=0;i<v[x].size();i++){
        int e=v[x][i].first;
        int w=v[x][i].second;
        if(dis[x]+w<dis[e]){
            dis[e]=dis[x]+w;//check if the next vertex distance could be minimized
            s.insert({dis[e],e});//insert the next vertex with the updated distance
        }
    }

}

//showing distance of all nodes from source node 1
for(int i=2;i<=n;i++)
    cout<<i<<" "<<dis[i]<<endl;



}

int main(){

int s,m,n,from,next,weight;
cout<<"enter no. of nodes and no. of edges : ";
cin>>n>>m;
cout<<"enter edges from ,next and weight : ";
for(int i=0;i<m;i++){
    cin>>from>>next>>weight;
    v[from].push_back({next,weight});
}

dijkstra(n);


return 0;
}
