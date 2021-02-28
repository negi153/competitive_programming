#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> a[10];//graph
int visited[10];

void BFS(int s){

queue<int> q;

q.push(s);
visited[s]=1;
cout<<s<<" ";

while(!q.empty()){
    int n=q.front();
    q.pop();

    for(int i=0;i<a[n].size();i++){
        if(visited[a[n][i]]==0){
            visited[a[n][i]]=1;
            q.push(a[n][i]);
            cout<<a[n][i]<<" ";
        }
    }

}


}

int main(){
int nodes,edges,x,y,start;
cout<<"enter no. of nodes and no of edges: ";
cin>>nodes>>edges;
cout<<"enter "<<edges<<" edges: ";
for(int i=0;i<edges;i++)
{
    cin>>x>>y;
    a[x].push_back(y);
    a[y].push_back(x);
}

cout<<"enter the starting node : ";
cin>>start;

BFS(start);//source node is 0

return 0;
}
