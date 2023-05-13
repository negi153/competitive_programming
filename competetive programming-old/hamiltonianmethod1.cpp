#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a[100][100];

/*
A Hamiltonian Path in a graph having N vertices is nothing but a permutation
of the vertices of the graph [v1, v2, v3, ......vN-1, vN] ,
 such that there is an edge between vi and vi+1 where 1 ≤ i ≤ N-1.
So it can be checked for all permutations of the vertices
whether any of them represents a Hamiltonian Path or not.
*/
int hamiltonian(int n){

vector<int> nodes;
for(int i=1;i<=n;i++)//eg.  vector=> [1,2,3,4,5]
    nodes.push_back(i);

int c=0;

do{
bool ans=true;
for(int i=0;i<n-1;i++){
    if(a[nodes[i]][nodes[i+1]]==0){
        ans=false;
        break;
    }

}
    if(ans==true)
        c++;


}while(next_permutation(nodes.begin(),nodes.end()));//this function in algorithm header file,it will
//next big permutation

return c;
}

int main(){
//nodes from 1 to n
int n,m,x,y;
cout<<"enter the no. of node and no. of edges : ";
cin>>n>>m;
cout<<"enter edges : ";
while(m--){
cin>>x>>y;
a[x][y]=1;
a[y][x]=1;
    }

cout<<"no. of hamiltonian paths are : "<<hamiltonian(n);

return 0;
}

