#include <iostream>
// #include<limit.h>
using namespace std;

//print extremene elements
// 2 8 3 7 1 4 15

int main() {
 
 int n=7;
 int a[7]={2,3,1,15,4,7,8};
 
int start=0,end=6;

while(start<=end){
  
  if(start==end)
     cout<<a[start]<<" ";
  else
    cout<<a[start]<<" "<<a[end]<<" ";
  
  start++;
  end--;
}

  return 0;
}