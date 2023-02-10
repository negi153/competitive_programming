#include <iostream>
using namespace std;


// print the double of elements of array

void method1(){
  int a[5] = {1,3,5,7,9};
  for(int i=0;i<5;i++){
    cout<<2*a[i]<<" ";
  } 

  cout<<endl;
}

void method2(){
  int b[500];
  int n; cin>>n;

  for(int i=0;i<n;i++) cin>>b[i];

  for(int i=0;i<n;i++) cout<<b[i] *2<<" ";
}

int main() {
  
  method1();


  method2();

  return 0;
}