
#include <iostream>
#include<vector>

using namespace std;

int a[100][100],v[100];
vector<int> s;

void top(int i,int n){

    v[i]=1;
    for(int j=1;j<=n;j++){
        if(a[i][j]==1 && v[j]==0)
            top(j,n);
    }
    s.push_back(i);
}

int main() {
	int n,m,x,y;
	cout<<"enter no. of nodes and no. of edges : ";
    cin>>n>>m;
    cout<<"enter directed edges : ";
    while(m--){
        cin>>x>>y;
        a[x][y]=1;
    }


for(int i=1;i<=n;i++){
    if(v[i]==0)
        top(i,n);
}

//showing output of topological sort of elements
//or we can use stack to store elements of topological sort
cout<<"topological sorting : \n";
for(int i=s.size()-1;i>=0;i--)
cout<<s[i]<<" ";

    return 0;
}

