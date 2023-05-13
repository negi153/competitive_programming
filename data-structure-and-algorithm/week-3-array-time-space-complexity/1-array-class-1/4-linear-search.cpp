#include <iostream>
using namespace std;

// /Linear search

void findElement(int a[],int n,int k){
  int found=0;
  for(int i=0;i<n;i++){
    if(a[i]==k)
      {
        found=1;
        break;
      }
  }

  if (found) cout<<"found";
  else cout<<"not found";
}

int main() {
 
 int a[10]={1,2,5,6};
int size = 4,k=15;

findElement(a,size,k);

  return 0;
}