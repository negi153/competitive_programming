// find first occurance of element in sorted order
// eg. a = {1,2,2,2,3,5,5,5,5,8}
// first occurance of 5 is at index 5

#include <iostream>
#include<vector>

using namespace std;

int find_last_occurance_by_binary_search(vector<int>& arr, int target){ // o(logn) --> as it follows binary search

  int start = 0, end=arr.size()-1, mid, lastOccuranceIndex = -1;

  while(start<=end){
    mid = start + (end-start)/2;

    if(arr[mid] == target){ // if mid element is equal to target then, save the index and search in right(because possibility is that answer might be in right side)
      lastOccuranceIndex = mid; // store the index
      start = mid + 1 ;// look into right for last index
    }
    else if(target > arr[mid]){ // if target element is more than mid, then look into right side
      start = mid+1;
    }
    else{ // if target is less than mid, then look into left side
      end  = mid-1;
    }
  }

  return lastOccuranceIndex; // return index of left ocurance
}

int main() {
  
  vector<int> arr{1,2,2,2,3,5,5,5,5,8};
  int target = 9;

  int lastOccurance = find_last_occurance_by_binary_search(arr,target);
  if(lastOccurance != -1)
    cout<<"last occurance of element "<<target<<" is "<<lastOccurance<<endl;
  else
    cout<<"element is not present in array"<<endl;

  return 0;
}