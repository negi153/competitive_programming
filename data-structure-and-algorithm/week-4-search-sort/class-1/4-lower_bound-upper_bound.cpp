// find first occurance of element in sorted order
// eg. a = {1,2,2,2,3,5,5,5,5,8}
// first occurance of 5 is at index 5

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
  
  vector<int> arr{1,2,2,2,3,5,5,5,5,8};
  int target = 8;


  // lower_bound / upper_bound is present in algorithm
  // for above functions, array should be in sorted order
  
  // lower_bound -> the function returns an iterator pointing to the next smallest number just greater than or equal to that number. 
  //If there are multiple values that are equal to val, lower_bound() returns the iterator of the first such value.
  // lower_bound --> gives index of element wherer element >= target
  auto ans = lower_bound(arr.begin(),arr.end(),target); // it gives the first occurance index
  if(ans != arr.end())
    cout<<"first occurance by lower bound - "<<ans-arr.begin()<<endl;
  else
    cout<<"element not found in array"<<endl;

  //upper_bound -It returns an iterator pointing to the first element in the range [first, last] that is greater than value, or last if no such element is found.
  // upper_bound -> gives index of element where element > target

  ans = upper_bound(arr.begin(),arr.end(),target); // it gives the first occurance index
    cout<<"index of element which is more than target - "<<ans-arr.begin()<<endl;
    cout<<"last occurance of element - "<<ans-arr.begin()-1<<endl;

  
  return 0;
}