// we have a stair, we are at bottom and oponnent is at top. we can only take steps which can be represented in the power of 2. find out the minimum number of steps to reach oponnent

//logic - 
    // suppose our oponnent is present at n.
    // and we can only use power of 2. so the minimum number of stpes would be number of set bits in n;
    // eg. n = 10
    // we can set steps -> 2, 4, 8 ....
    //     binary = 1 0 1 0
    //     it can be written as 
    //             1 0 0 0 = 8 = 2^3 
    //         or  0 0 1 0 = 2 = 2^1
    //         ---------------
    //             1 0 1 0

    //     means the number of minimum steps would be the number of set bits in n.

int setBitsCount(int n){
    int cnt=0;
    while(n!=0){
        n = n & (n-1)
        cnt++;
    }

    cout<<"number of inimum steps - "<<cnt;
}