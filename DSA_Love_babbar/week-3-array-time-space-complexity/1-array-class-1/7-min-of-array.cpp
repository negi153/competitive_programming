#include <iostream>
using namespace std;

//find min in array

int main() {
 
 int n=7;
 int a[7]={2,3,1,15,4,7,8};
 
 int mini = INT_MAX; // INT_MAX
// int maxy = -1;
 for(int i=0;i<n;i++){

   if(a[i]<mini)
    mini = a[i];
 }

  cout<<"minimum is - "<<mini;

  return 0;
}