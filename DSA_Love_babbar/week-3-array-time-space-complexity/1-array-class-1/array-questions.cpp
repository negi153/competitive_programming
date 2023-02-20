#include <iostream>
#include<limits.h>
using namespace std;

void count_zeroes_ones(int a[],int n){

  int zeroes=0,ones=0;
  for(int i=0;i<n;i++){
    if(a[i]==1) ones++;
    else if(a[i]==0) zeroes++;
  }

  cout<<"zeroes - "<<zeroes<<", Ones - "<<ones<<endl;

}

void MaxArray(int a[],int n){
  int maxy = INT_MIN;

  for(int i=0;i<n;i++){
    if(a[i]>maxy) 
      maxy = a[i];
  }

  cout<<"Max in array - "<<maxy<<endl;
}

void MinArray(int a[],int n){
  int mini = INT_MAX;

  for(int i=0;i<n;i++){
    if(a[i]<mini) 
      mini = a[i];
  }

  cout<<"Min in array - "<<mini<<endl;
}

void printExtreme(int a[],int n){
  cout<<"Print Extrement elements -";
  int i=0,j=n-1;
  while(i<=j){

    if(i==j)
      cout<<a[i]<<" ";
    else
      cout<<a[i]<<" "<<a[j]<<" ";
    
    i++;
    j--;
  }

  cout<<endl;

}

void reverseArray(int a[],int n){
  cout<<"array in reverse order - ";

  int i=0,j=n-1;
  while(i<=j){
    swap(a[i],a[j]);
    i++;
    j--;
  }

  for(int i=0;i<n;i++) cout<<a[i]<<" ";

  cout<<endl;
}

int main() {

  int a[]={1,1,0,0,0,1,0};
  int size = 7;

  count_zeroes_ones(a,size);


  int b[]={3,4,1,5,7,3};
  int n=6;
  MaxArray(b,n);
  MinArray(b,n);

  printExtreme(b,n);

  reverseArray(b,n);

  return 0;
}