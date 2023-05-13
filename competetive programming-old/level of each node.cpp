#include<iostream>>
#include<queue>
#include<vector>

using namespace std;

int level[10],visited[10];
vector<int> g[10];

void find_level_bfs(int s,int nodes){
queue<int> q;
q.push(s);
visited[s]=1;
level[s]=0;

while(!q.empty()){

    int p=q.front();
    q.pop();

    for(int i=0;i<g[p].size();i++){
            if(visited[g[p][i]]==0){
                visited[g[p][i]]=1;
                level[g[p][i]]=level[p]+1;
                q.push(g[p][i]);
            }
    }

}



}

int main(){
int nodes,edges,x,y,s;

cout<<"enter no. of nodes and edges : ";
cin>>nodes>>edges;

cout<<"enter edges : ";
for(int i=0;i<edges;i++){
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
}

cout<<"source node : ";
cin>>s;

find_level_bfs(s,nodes);

for(int i=0;i<nodes;i++)
        cout<<i<<" "<<level[i]<<"\n";

return 0;
}
