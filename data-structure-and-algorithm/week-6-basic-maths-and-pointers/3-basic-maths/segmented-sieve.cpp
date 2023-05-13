// Problem --> given a range from L to R, and we need to find the number of prime numbers between L to R. R> 10^8. here condition is (R-l)<= 10^6
// we could solve this problem with sieve of eratosthene but in this case R is very large and we can't create array of that much size so we can't use sieve of eratosthene direclty.
// can't create array more than 10^8


// Segmented sieve logic-->

// 1. create a sieve/array which will store all the primes between 2 to sqrt(R). using sieve of eratosthenes
// 2. for each prime between 2 and sqrt(R), mark all the multiples as false which comes between L and R.
// 3. count all the primes between L and R


#include <iostream>
#include<vector>
using namespace std;

# define Max 100001

vector<int> sieve_of_eratosthene(){ // nloglogn --> time

    vector<int> is_prime(Max,1);

    for(int i=2;i*i<Max;i++){
      if(is_prime[i]){
        for(int j=2*i;j<Max;j+=i)
          is_prime[j]=0;
      }
    }

    vector<int> primes;
    for(int i=2;i<Max;i++){
      if(is_prime[i])
        primes.push_back(i);
    }

  return primes;
}


void print_primes_by_segmented_sieve(int l, int r, vector<int>& primes){
  // this functio will print all the primes numbers between Range L-R.
  // this is sengmented sieve

  vector<int> is_prime(r-l+1,1); // create an array or segment of size r-l and mark all the elements as prime number
  // vector  --------> 0, 1, 2, ......., r-l-1
  // assume range ---> L, L+1, L+2.......R-1

  for(int i=0;primes[i] * primes[i] <= r ;i++){
    int cur_prime = primes[i];

    // find the left bound which is more than l
    // just smaller or equal to l
    int base_num = (l/cur_prime)*cur_prime;

    if (base_num<l)
        base_num += cur_prime;

    // mark all the multiples of prime number within L to R as false
    for(int j=base_num; j<=r; j+=cur_prime)
      is_prime[j-l] = 0;

    // there may be a case when base is itself a prime number
    if(base_num == cur_prime)
        is_prime[base_num-l] = 1;

  }

  cout<<"prime between "<<l<<"and "<<r<<" -> ";
  for(int i=0;i<r-l;i++){
    if(is_prime[i]){
        if(i+l > 1)
        cout<<i+l<<" ";
    }
  }
cout<<endl;

}


int main() {
  
  vector<int> ans = sieve_of_eratosthene();
  // for(auto x:ans) cout<<x<<endl;
  // cout<<endl;

  int t;cin>>t;
  while(t--){
    int l,r;
    cin>>l>>r;
    print_primes_by_segmented_sieve(l,r,ans);
  }


  return 0;
}