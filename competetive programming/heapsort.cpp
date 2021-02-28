#include<iostream>
#include<algorithm>

using namespace std;

void max_heapify(int a[],int i,int heap_size){

int largest=i;
int left=2*i,right=2*i+1;

if(a[i]<a[left] && left<=heap_size)
largest=left;

if(a[largest]<a[right] && right<=heap_size)
    largest=right;

if(largest!=i){
    swap(a[i],a[largest]);
    max_heapify(a,largest,heap_size);
}


}

void build_maxheap(int a[],int n){
for(int i=n/2;i>=1;i--){
    max_heapify(a,i,n);
}
}

void heapsort(int a[],int n){

int heap_size=n;

build_maxheap(a,n);

for(int i=n;i>=2;i--){

    swap(a[i],a[1]);
    heap_size-=1;
    max_heapify(a,1,heap_size);
}

}

int main(){

int n;
cin>>n;

int a[n+1];
for(int i=1;i<=n;i++)
    cin>>a[i];

heapsort(a,n);

for(int i=1;i<=n;i++)
    cout<<a[i]<<" ";


return 0;
}
