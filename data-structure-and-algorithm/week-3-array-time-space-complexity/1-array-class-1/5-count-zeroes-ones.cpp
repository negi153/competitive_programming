#include <iostream>
using namespace std;

//count zeroes and one

int main() {
 
 int n=10;
 int a[10]={0,0,1,1,1,1,0,0,1,1,};
 
 int countZeroes = 0, countOnes=0;

 for(int i=0;i<n;i++){
   if(a[i]==0) countZeroes++;
   else countOnes++;
 }

 cout<<"no. of zeroes "<<countZeroes<<endl;
 cout<<"no. of ones "<<countOnes<<endl;

  return 0;
}