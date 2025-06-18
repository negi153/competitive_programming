// str = "abc"
// power set or subsequence - 2 ^n (n = length of string)
//     "",
//     a
//     b
//     c
//     ab
//     bc
//     ac
//     abc

// take sequence from 0 to 2^n - 1 
//     421
// 0 - 000
// 1 - 001
// 2 - 010
// 3 - 011
// 4 - 100
// 5 - 101
// 6 - 110
// 7 - 111

// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

void getSubsequence(string str){
    // exponential time complexity
    vector<string> ans;
    int n= str.length();

    // iterate from 0 to 2^n -1
    for(int num=0;num < (1<<n); num++){
        string temp = "";
        
        for(int i=0;i<n;i++){
            char ch = str[i];

            if((num & (1<<i)) != 0)
                temp = temp + ch;
        }
        
        ans.push_back(temp);
    }

    for(auto x: ans) cout<<x<<endl;
}

int main() {
    string str = "abc";
    
    getSubsequence(str);

    return 0;
}