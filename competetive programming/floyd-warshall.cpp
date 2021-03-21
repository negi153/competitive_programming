#include<iostream>

// all pair shortest path problem --> it finds the shortest path between all pairs of vertex in graph.
// applicable on directed and undirected graph.
// it is a dynamic programming algorithm. it can work when graph has negative weight edges.
// and with variation it can also detect the negative weight cycle in the graph
// time complexity o(v^3)

using namespace std;

int a[1000][1000];
int dis[1000][1000];
int maxx=1e9+7;

void floyd_warshall(int n,int m){

//initialising distance of every node from every other node as infinity
// initialising distance of node a from a = 0    
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        if(i!=j)
            dis[i][j]=maxx;
        else
            a[i][j]=0;

//initialising distances from input weights
for(int j=0;j<n;j++){
    for(int k=0;k<n;k++)
        dis[j][k]=a[j][k];
    }
    

//logic-->
//traversing in whole array
//when i =0 that means we are checking if we can get better distance
// by includiing node 0
//when i =1 that means we are checking if we can get better distances
//by including node 0 and 1
//and it goes 
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
            dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
        }
    }
}


//showing distacaes;

    for(int j=0;j<n;j++){

        for(int k=0;k<n;k++){
            cout<<dis[j][k]<<" ";
        }
        cout<<"\n";
    }

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



for(int i=0;i<m;i++){
    cin>>from>>next>>weight;
    a[from][next]=weight;
    }

floyd_warshall(n,m);//it will  find shortest distance of every node from every other node


return 0;
}
