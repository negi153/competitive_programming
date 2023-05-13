#include<iostream>
#include<vector>

using namespace std;

vector<int> a[10];
int visited[10];


void dfs_recursive(int k){

visited[k]=1;
cout<<k<<" ";

for(int i=0;i<a[k].size();i++){
    if(visited[a[k][i]]==0){
        dfs_recursive(a[k][i]);
    }
}

}

int main(){
int nodes,edges,x,y;
cin>>nodes>>edges;

for(int i=0;i<edges;i++){
    cin>>x>>y;
    a[x].push_back(y);
    a[y].push_back(x);
}
cout<<"enter sourcde : ";
int s;
cin>>s;


dfs_recursive(s);
return 0;
}
