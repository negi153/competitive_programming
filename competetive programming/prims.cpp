#include<iostream>
#include<vector>
#include<queue>


using namespace std;

typedef pair<int,int> pi;
const int MAX=1e4+5;
vector<pi> a[MAX];
int visited[MAX];
int nodes,edges,x,y,weight;


int prims(int n){

int min_cost=0;
priority_queue<pi,vector<pi>,greater<pi> > p;//min_heap

p.push(make_pair(0,n));

pi q;

while(!p.empty()){

    q=p.top();
    p.pop();
    int x=q.second;

    if(visited[x]==0){
        visited[x]=1;
        min_cost=min_cost+q.first;
        for(int i=0;i<a[x].size();i++){
                int y=a[x][i].second;
            if(visited[y]==0){
                p.push(a[x][i]);
            }
        }
    }
}

return min_cost;
}



int main(){

cout<<"enter no. of nodes,edges :";
cin>>nodes>>edges;

cout<<"enter edges between nodes with weight :";
for(int i=0;i<edges;i++){
    cin>>x>>y>>weight;
    a[x].push_back(make_pair(weight,y));
    a[y].push_back(make_pair(weight,x));
}

int ans=prims(1);
cout<<"cost is : "<<ans;

return 0;
}
