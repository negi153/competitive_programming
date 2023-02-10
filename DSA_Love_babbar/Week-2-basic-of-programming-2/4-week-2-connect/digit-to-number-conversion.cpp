// program to generate number from digits

#include <iostream>
#include<math>

using namespace std;
int main() {
   int n,num,ans=0;
   cin>>n;

 for(int i=0;i<n;i++)
 {
//   // cout<<"Enter a number";
   cin>>num;
   ans=(ans*10)+num;
}
 cout<<"answer is "<<ans<<endl;


}

  return 0;
}