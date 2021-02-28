
#include<iostream>
#define IN_STACK 1
#define NOT_IN_STACK 0

using namespace std;

int a[100][100],label[100];

bool dfs(int v,int instack_count,int n){
if(instack_count==n)
    return true;
for(int i=0;i<n;i++){
    if(a[v][i] && label[i]==NOT_IN_STACK){
        label[i]=IN_STACK;
        if(dfs(i,instack_count+1,n))
            return true;
        label[i]=NOT_IN_STACK;
    }
}

return false;
}

bool check_using_dfs(int n){

for(int i=0;i<n;i++){
    label[i]=IN_STACK;
    if(dfs(i,1,n))
        return true;
    label[i]=NOT_IN_STACK;

}
return false;

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

    if(check_using_dfs(n))
cout<<"hamiltonian paths exist";
else
    cout<<"hamiltonian path does not exist";

return 0;
}

