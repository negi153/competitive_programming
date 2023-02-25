// find a target element in rotated and sorted array//
// eg. a=[3,4,5,6,7,1,2]
// from 3 to 7, it is incresing graph. and after that again from 1 to 2 it is increasing. there are 2 increasing lines but a drop down in middle.
// in many places 7 is the pivot element and in many places 1 is pivot

// pivot element is that element where some change is happening.
// and pivot element > previous element && previous element > next element.

#include <iostream>
# include<vector>
#include<algorithm>

using namespace std;

int find_Pivot_Index(vector<int> &v){ // linear serach - o(log n)

  int start = 0,end=v.size()-1,mid,pivot = -1;

  while(start<=end){

      mid = start + (end-start)/2;

      if(mid+1 < v.size() && v[mid]>v[mid+1]){ // handling case when mid is the pivot 
          return mid;
      }

      if(mid-1 >=0 && v[mid] < v[mid-1]){ // handling case when mid-1 is the pivot
        return mid-1;
        
      }

      if(v[start] > v[mid]) { // if start element > mid element --> search in left
        end = mid-1;
      }
      else if(v[start] <= v[mid]) // if start element < mid eleent --> search in right
      {
        start = mid+1;
      }
  }

  return -1;

}

void find_target_in_sorted_and_rotated_array(vector<int> &v,int target){ // linear serach - o(log n)

  int pivot_index = find_Pivot_Index(v);
  cout<<"pivot index is - "<<pivot_index<<endl;

  if(target >= v[0] && target <= v[pivot_index]) 
    cout<< "target index - "<<lower_bound(v.begin(),v.begin()+pivot_index,target)-v.begin()<<endl;
  else if(target >= v[pivot_index+1] && target <= v[v.size()-1])
    cout<<"target index - "<<lower_bound(v.begin()+pivot_index+1,v.end(),target)-v.begin()<<endl;

  else
    cout<<"not found"<<endl;

}

int main() {
  
  vector<int> v{3,4,5,6,7,1,2};

  int target = 12;
  find_target_in_sorted_and_rotated_array(v,target);

  return 0;
}