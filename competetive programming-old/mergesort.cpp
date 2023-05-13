#include<iostream>
using namespace std;


void merge_combine(int a[],int first,int mid,int last){
int temp[last-first+1],k=0;
int p=first,q=mid+1;

for(int i=first;i<=last;i++){
    if(p>mid)
        temp[k++]=a[q++];
    else if(q>last)
        temp[k++]=a[p++];
    else if(a[p]>a[q])
        temp[k++]=a[q++];
    else
        temp[k++]=a[p++];
    }
    for(int i=0;i<k;i++)
        a[first++]=temp[i];

}

void merge_split(int a[],int first,int last){

if(first<last){
    int mid=(first+last)/2;

    merge_split(a,first,mid);
    merge_split(a,mid+1,last);
    merge_combine(a,first,mid,last);
}

}


int main(){
int a[10];
for(int i=0;i<10;i++)
    cin>>a[i];

merge_split(a,0,9);
for(int i=0;i<10;i++)
cout<<a[i]<<" ";



return 0;
}
