#include<iostream>
#include<stdlib.h>
using namespace std;




int partion(int a[],int first,int last){

int i=first+1;
int piv=a[first];

for(int j=first+1;j<=last;j++){

    if(a[j]<piv){
        swap(a[j],a[i]);
        i++;
    }

}

swap(a[first],a[i-1]);
return i-1;

}


int rand_partition(int a[],int first,int last){

int r=first+rand()%(last-first+1);
swap(a[r],a[first]);
return partion(a,first,last);

}


void quick_sort(int a[],int first,int last){

if(first<last){

int q=rand_partition(a,first,last);
quick_sort(a,first,q-1);
quick_sort(a,q+1,last);

}

}

int main(){

int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
    cin>>a[i];

quick_sort(a,0,n-1);

for(int i=0;i<n;i++)
    cout<<a[i]<<" ";

return 0;
}
