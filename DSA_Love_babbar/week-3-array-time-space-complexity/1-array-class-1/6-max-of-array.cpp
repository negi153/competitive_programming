#include <iostream>
using namespace std;

//find max in array

int main() {
 
 int n=7;
 int a[7]={2,3,1,15,4,7,8};
 
 int maxy = INT_MIN; // INT_MAX
// int maxy = -1;
 for(int i=0;i<n;i++){

   if(a[i]>maxy)
    maxy = a[i];
 }

  cout<<"maximum is - "<<maxy;

  return 0;
}