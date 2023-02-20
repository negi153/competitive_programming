#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int binary_search1(int arr[],int n, int target){ // binary search work on sorted array
    // n/2^1. . n/2^2.. n/2^3....n/2^k

    // n/2^k = 1
    // k = lon (base 2)

    // time complexity -> o(logn)

  int start=0,end=n-1,mid;

  while(start<=end){

    // mid = (start + end)/2;  // it can give integer overflow . eg. if start = 2^31-1 and end = 2^31 -1 . start + end will give integer overflow

    mid = start + (end-start)/2 ; // this won't give integer overflow

    if(arr[mid] == target) 
      return mid;
    else if(target < arr[mid]) // serarch in left
      end = mid-1;
    else // search in right
      start = mid+1;
  }

  return -1; // return -1 if elment not found
}

int main() {
  
  int arr[]={1,2,4,6,9,11};
  int n=6;
  int target = 10;

  int element_index  = binary_search1(arr,n,target);

  cout<<"binary search code - ";
  if(element_index != -1)
    cout<<"element found at "<<element_index<<endl;
  else
    cout<<"element not found"<<endl;
  
  cout<<"STL inbuild binary search -";
  vector<int> v{3,4,6,7,8};
  if(binary_search(v.begin(),v.end(),6))
    cout<<"element found"<<endl;
  else
    cout<<"element not found"<<endl;

  cout<<"STL inbuild binary search in array -";
  if(binary_search(arr,arr+6,7))
    cout<<"element found"<<endl;
  else
    cout<<"element not found"<<endl;

  return 0;
}