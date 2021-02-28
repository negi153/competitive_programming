#include<iostream>
#include<vector>

using namespace std;

vector<int> v[2000+10];
int dis[1000+10];

void bellman(int n,int m,int s){
    int u,r,w;

for(int i=0;i<n;i++){
    dis[i]=2e9;
}

dis[s]=0;
for(int i=0;i<n-1;i++){

    for(int j=0;j<m;j++){
            u=v[j][0];
            r=v[j][1];
            w=v[j][2];

            if(dis[u]+w<dis[r])
                dis[r]=dis[u]+w;
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

int s,m,n,from,next,weight;
cout<<"enter no. of nodes and no. of edges : ";
cin>>n>>m;
cout<<"enter edges from ,next and weight : ";
for(int i=0;i<m;i++){
    cin>>from>>next>>weight;
    v[i].push_back(from);
    v[i].push_back(next);
    v[i].push_back(weight);
}
cout<<"enter source node : ";
cin>>s;

bellman(n,m,s);


return 0;
}
