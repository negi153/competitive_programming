#include<iostream>
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


void quick_sort(int a[],int first,int last){
if(first<last){
    int q=partion(a,first,last);
    quick_sort(a,first,q-1);
    quick_sort(a,q+1,last);
}
}

int main(){

int a[10];
for(int i=0;i<10;i++)
    cin>>a[i];

quick_sort(a,0,9);

for(int i=0;i<10;i++)
    cout<<a[i]<<" ";


return 0;
}
