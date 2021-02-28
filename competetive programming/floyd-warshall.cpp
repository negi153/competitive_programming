#include<iostream>

using namespace std;

int a[1000][1000];

void floyd_warshall(int n,int m){

for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        for(int k=1;k<=n;k++){
            a[j][k]=min(a[j][k],a[j][i]+a[i][k]);
        }
    }
}


//showing distacaes;

    for(int j=1;j<=n;j++){

        for(int k=1;k<=n;k++){
            cout<<a[j][k]<<" ";
        }
        cout<<"\n";
    }

}

int main(){

int s,m,n,from,next,weight;
cout<<"enter no. of nodes and no. of edges : ";
cin>>n>>m;
cout<<"enter edges from ,next and weight : ";
for(int i=0;i<m;i++){
    cin>>from>>next>>weight;
    a[from][next]=weight;
    a[next][from]=weight;
}

floyd_warshall(n,m);//it will  find shortest distance of every node from every other node


return 0;
}
