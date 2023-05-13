#include <iostream>
using namespace std;
// arrya uses pass by reference that means here a and b array ppointing
// out to same memory location.
// any changes made in below functin will change the actual array. that means it 
// uses pass by reference

// in pass by value, duplicate variable will be used in function
void changeArray(int b[],int n){
  b[0] = 5;
  b[1] = 7;

  cout<<b[0]<<" "<<b[1]<<endl; //5 7
}

int main() {
 
 int a[10]={1,2};

  changeArray(a,2);

    cout<<a[0]<<" "<<a[1]<<endl; //5 7

  return 0;
}