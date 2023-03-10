class Solution {
public:


    bool isPrimeSqrt(int n){ // time --> o(sqrt of n)

        if(n<=1) // if number is less than 2, then it's not prime 
            return false;

        int s = sqrt(n);

        for(int i=2;i<= s;i++){
            if(n % i == 0) // not a prime
                return false;
        }

        return true; // it is prime number

    }

    bool isPrime(int n){ // time --> o(n)

        if(n<=1) // if number is less than 2, then it's not prime 
            return false;

        for(int i=2;i<n;i++){
            if(n % i == 0) // not a prime
                return false;
        }

        return true; // it is prime number

    }

    int countPrimes1(int n) { // basic approach --> time complexity --> o(n^2) 
        
        int prime_num_count = 0;
        for(int i=2; i<n; i++){ 
            //  if(isPrime(i))  
            //     prime_num_count++;

            if(isPrimeSqrt(i)) // 
                prime_num_count++;
        }

        return prime_num_count;
    }


    int sieve_of_eratosthene(int n){

        if(n==0)
            return 0;

        vector<int> is_prime(n,1);

        int ans =0;

        for(int i=2;i<n;i++){
            if(is_prime[i]){ // if i is prime number, then mark all the multiple of i as non prime
                ans++;
                int k=2*i;

                while(k < n){
                    is_prime[k]=0;
                    k+=i;
                }

            }
        }

        return ans;

    }

    int countPrimes(int n){
        
        return sieve_of_eratosthene(n);

    }

};