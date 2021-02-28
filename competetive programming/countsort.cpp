#include<iostream>

using namespace std;

void countsort(int a[],int n){

int m=0;
for(int i=0;i<n;i++)
    m=max(m,a[i]);

int c[m+1];//count array to count the frequency of elements of array a

for(int i=0;i<=m;i++)//initialise count array
    c[i]=0;

for(int i=0;i<n;i++)//count frequency
    c[a[i]]++;

int j=0;
for(int i=0;i<=m;i++){
    int frequency=c[i];
    while(frequency--){
        a[j++]=i;

    }
}



}

int main(){

int n;
cin>>n;

int a[n];
for(int i=0;i<n;i++)
    cin>>a[i];

countsort(a,n);

for(int i=0;i<n;i++)
    cout<<a[i]<<" ";

return 0;
}
