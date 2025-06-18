#include<iostrea>
using namespace std;

void clearIthBit(int n i, int i){
    mask = ~(1<<i);
    int ans3 = n & mask; // it will set ith bit to 0
    return ans3;
}

void updateIthBit(int n,int i, int target)
    {
            clearIthBit(n,i);
            int mask = target <<i;
            n = n | mask;
            cout<<"update ith bit "<<n<<endl;

    }


void clearLastIBits(int n, int i){
    int mask = (-1 << i);
    n = n & mask;
    cout<<"after clearing last i bits : "<<n;
}

bool checkPowerOf2(int n){
    if((n & (n-1)) == 0) // it if power of 2
        return true;
    else 
        return false;
}

void countSetbits(int n){
    // log n - time complexity
    int c = 0
    while(n != 0 ){
        int lastBit = n & 1;
        if(lastBit== 1)
            c++;

        n = n >> 1; // right shift
    }

    cout<<"number of set bits : "<<c;
}

int countSetBitsFast(int n){
    // time - o(number of set bits)

     int count = 0;
     while(n!=0){
        // remove last set bit
        n = (n & (n-1));
        count++;
     }

     cout<<"number of set bits : "<<count
}


int clearBitsInRange(int n, int i, int j){
    // in a binary number, 0 index start from right.
    // set 0 from i (left) to j index(right)
    //           i       j
    // 1 1 1 1 0 1 0 1 0 1 1 1 1
 // index -> 9 8 7 6 5 4 3 2 1 0    

    int a = (-1 <<(i+1));
    int b = (1<<j) - 1;
    int mask = a | b;

    n = n & mask;
    cout<<"after clearning in range - "<<n<<endl;

}

int main(){

    int n= 5;
    // even / odd
    if(n&1)
        cout<<"odd"<<endl;
    else
        cout<<"even";

    // check if ith bit is 1 or 0
    int i = 2; // check ith bit
    int mask = 1<<i; // left shift i times
    int ans = n & mask; // if ans is 1, then ith bit is 1 else 0
    cout<<"ith bit is "<<ans<<endl;


    // set ith bit. means put 1 in ith bit from left(starting from 0)
    i = 3;
     mask = 1<<i; // create mask by shifting to left
    int setAns = n | mask; // change ith bit to 1

    // clear ith bit means put 0 in ith bit
    i = 2;
    mask = ~(1<<i);
    int ans3 = n & mask; // it will set ith bit to 0

    updateIthBit(n,0,1);

    n = 7;
    clearLastIBits(n,2);

    n = 16;
    checkPowerOf2(16);


    countSetbits(n);
     
    countSetBitsFast(n);


    clearBitsInRange(n,i,j);

    return 0;
}