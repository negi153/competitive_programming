int sieve_of_eratosthene(int n){ // o(n log log n)

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