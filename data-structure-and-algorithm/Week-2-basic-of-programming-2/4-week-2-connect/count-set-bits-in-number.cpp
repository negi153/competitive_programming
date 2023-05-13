// QUES --> Count the set bits in binary representation of a number;
// SET BITS --> the bit which is ON or (1);
#include <iostream>
using namespace std;

void method1(int n)
{
  // in this method,we have converted the no. into binary number first 
  // and then we have counted the ones(1) for set bits. 
   int rem,count=0;
  while(n>0)
  {
    rem=n%2;
    if(rem==1)
    {
      count++;
    }
    n=n/2;
  }
  cout<<"Method 1 Set bits are : "<<count<<endl;
}

int method2(int n)
{
  // in this method,we have converted the no. into binary number first 
  // and then we have counted the ones(1) for set bits. 

  if (n==0)
  {  // if number is zero , then
  cout<<"Method 2 Set bits are : "<<0<<endl;
  return 0;
}
   int rem,count=0;
  while(n!=1) // in this condition, last iteration was skipping
  {
    rem=n%2;
    if(rem==1)
    {
      count++;
    }
    n=n/2;
  }

  cout<<"Method 2 Set bits are : "<<count+1<<endl; // here increment 1 is to consider the last bit

}

void method3(int n)
{
  int count=0;
  while(n!=0)
  {
    if(n & 1 )   // bitwise and --> this line tells that last bit is 1 then it
    {               // count the bits.
      count++;
    } 
    n=n>>1;    // right shift bitwise operator --> it is removing last bit.

  }
  cout<<"Total bits by BITWISE OPERATOR are : "<<count<<endl;
}
int main() {
int n;
cin>>n;

method1(n);
method2(n);
method3(n);

  return 0;
}