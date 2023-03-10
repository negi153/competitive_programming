#include <iostream>
using namespace std;

int slowExponentiation(int a, int b){

  // find a^b

  // time complexity --> o(b)

  int ans = 1;
  for(int i=0;i<b;i++){
    ans = ans * a;
  }

  return ans;

}

int fastExponentiation(int a,int b){  // time complexity --> o(log b)

  int ans=1;

  while(b>0){
    cout<<"b - "<<b;
    if(b & 1){ // if b is odd
      ans = ans*a;
    }
    cout<<", ans - "<<ans;
    a = a*a;

    cout<<", a - "<<a<<endl;
    b = b>>1; // ritht shift -> divide by 2

  }

  return ans;

}


int main() {
  cout << "slow exponentiation - "<<slowExponentiation(5,5)<<endl;
  cout<< "fast exponentiation - "<<endl<<fastExponentiation(5,5)<<endl;
  return 0;
}