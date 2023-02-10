#include <iostream>
// #include<limit.h>
using namespace std;

//reverse array --> swap extreme elements
// 2 8 3 7 1 4 15

int main() {
 
 int n=7;
 int a[7]={2,3,1,15,4,7,8};
 
 int start = 0,end=6;
 while(start<=end){

   swap(a[start],a[end]);

   start++;
   end--;
 }

for(int i=0;i<n;i++) cout<<a[i]<<" ";

  return 0;
}