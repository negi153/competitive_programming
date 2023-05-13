#include<iostream>
#include<algorithm>

using namespace std;
const int MAX=1e4+5;

pair<int,pair<int,int> > p[MAX];
int id[MAX],nodes,edges;

void initialise(){

for(int i=0;i<=nodes;i++)
    id[i]=i;

}

int root(int x){

while(id[x]!=x){
    id[x]=id[id[x]];
    x=id[x];
}

return x;
}


void union1(int x,int y){

int p=root(x);
int q=root(y);
id[p]=id[q];

}

int krukshal(){

initialise();
sort(p,p+edges);
int min_cost=0;

int x,y,w;

for(int i=0;i<edges;i++){
    w=p[i].first;
    x=p[i].second.first;
    y=p[i].second.second;

    if(root(x)!=root(y)){
        min_cost=min_cost+w;
        union1(x,y);
    }


}

return min_cost;
}

int main(){
int x,y,w;

cout<<"enter nodes : ";
cin>>nodes;
cout<<"enter no. of edges : ";
cin>>edges;
cout<<"enter edges and weight(x y w) : ";
for(int i=0;i<edges;i++){
    cin>>x>>y>>w;
    p[i]=make_pair(w,make_pair(x,y));
}

int cost=krukshal();

cout<<cost;

return 0;
}
