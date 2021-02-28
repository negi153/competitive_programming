
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> a[10];//graph
int visited[10];

int minimum_distance_using_BFS(int s,int destination,int w){

queue<int> q;
int d=0;

q.push(s);
visited[s]=1;


while(!q.empty()){
    int n=q.front();
    q.pop();

    for(int i=0;i<a[n].size();i++){
        if(visited[a[n][i]]==0){
            visited[a[n][i]]=1;
            q.push(a[n][i]);
            if(a[n][i]==destination)
                return d+w;
        }
    }
d=d+w;
}


}

int main(){
int nodes,edges,x,y,start,destination,weight;
cout<<"enter no. of nodes and no of edges: ";
cin>>nodes>>edges;
cout<<"enter "<<edges<<" edges: ";
for(int i=0;i<edges;i++)
{
    cin>>x>>y;
    a[x].push_back(y);
    a[y].push_back(x);
}
cout<<"enter weight of edge(same for every edge): ";
cin>>weight;
cout<<"enter the source node and destination node : ";
cin>>start>>destination;

cout<<"minimum distance is : "<<minimum_distance_using_BFS(start,destination,weight);//source node is 0

return 0;
}
