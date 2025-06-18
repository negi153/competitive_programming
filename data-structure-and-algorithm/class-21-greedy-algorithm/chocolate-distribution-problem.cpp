// https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1


// Question - we have n packet of chocolates, each packet has some number of chocolate and we need to distribute it among students based on below condition - 
    // 1. each students gets exactly 1 packet
    // 2. difference between max number of chocolate given to a student and min number of chocolate given to a student is minimum


// logic - 
    1. sort the candies in increasing order
    2. apply sliding window of size M.
    3. initially, left = 0, and right = m-1
    4. move the window from left to right and find the answer
#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;


int main(){

    int n = 8; // chocolate packets
    int m = 5; // students
    int chocolate[] = {3,4,1,9,56,7,9,12}; // number of chocolate.

    sort(chocolate,chocolate+n); // sort in increasing order

    int ans = INT_MAX;

    int left = 0,right = m-1;
    while(right<n){
        ans = min(ans, chocolate[right] - chocolate[left]);
        right++;
        left++;
    }

    cout<<ans<<" ";
}