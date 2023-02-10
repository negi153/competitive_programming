#include <iostream>
using namespace std;




int main() {
 
 int a[10]={1,2};
 for(int i=0;i<10;i++) cout<<a[i]<<" ";  // 1 2 0 0 0 0 0 0 0 0  --> initialise all other with 0
 cout<<endl;

  int b[10];
 for(int i=0;i<10;i++) cout<<b[i]<<" ";  // it will give garbage

cout<<endl;

 int c[10]={0};
 for(int i=0;i<10;i++) cout<<c[i]<<" ";  // 0 0 0 0 0 0 0 0 0 0  it will give zeroes

cout<<endl;

 int d[10]={1};
 for(int i=0;i<10;i++) cout<<d[i]<<" ";  // 1 0 0 0 0 0 0 0 0 0   it will give zeroes after 1

  return 0;
}