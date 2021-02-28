#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void bucketsort(float a[],int n){

vector<float> b[10];
for(int i=0;i<n;i++){
    int bi=int(10*a[i])%10;
    b[bi].push_back(a[i]);
}

for(int i=0;i<n;i++)
    sort(b[i].begin(),b[i].end());

//concatenate all bucket
int index=0;
for(int i=0;i<n;i++){
    for(int j=0;j<b[i].size();j++)
        a[index++]=b[i][j];
}

}

int main(){

int n;
cin>>n;

float a[n];
for(int i=0;i<n;i++)
    cin>>a[i];

bucketsort(a,n);

for(int i=0;i<n;i++)
    cout<<a[i]<<" ";



return 0;
}
