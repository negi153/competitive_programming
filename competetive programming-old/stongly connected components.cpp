//Kosaraju's Linear time algorithm to find Strongly Connected Components:
#include<iostream>
#include<vector>
#include<string.h>
#include<stack>

using namespace std;

vector<int> adj[1000],reverse_adj[1000];
int vis[1000];
stack<int> p;

void dfs(int s){

vis[s]=1;
for(int i=0;i<adj[s].size();i++){
    if(vis[adj[s][i]]==0)
        dfs(adj[s][i]);
}
p.push(s);
}

void rev_dfs(int s){
cout<<s<<" ";
vis[s]=1;
for(int i=0;i<reverse_adj[s].size();i++){
    if(vis[reverse_adj[s][i]]==0)
        rev_dfs(reverse_adj[s][i]);
}

}

void kosaraju(int n){

//dfs on original graph
for(int i=1;i<=n;i++){
    if(vis[i]==0)
        dfs(i);
}

//reverse the directed edges of original graph
for(int i=1;i<=n;i++){
    for(int j=0;j<adj[i].size();j++){
            reverse_adj[adj[i][j]].push_back(i);
    }
}

//dfs on reverse adjacentcy list
memset(vis,0,sizeof(vis));

while(!p.empty()){
    int source=p.top();
    p.pop();
    if(vis[source]==0){
        rev_dfs(source);
        cout<<endl;
    }

}


}

int main(){

int m,n,from,next;
cout<<"enter no. of nodes and no. of edges : ";
cin>>n>>m;
cout<<"enter edges from ,next : ";
for(int i=0;i<m;i++){
    cin>>from>>next;
    adj[from].push_back(next);

}

cout<<"strongly connected components are on single line:\n";

kosaraju(n);

return 0;
}

