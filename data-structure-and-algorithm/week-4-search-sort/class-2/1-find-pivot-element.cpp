// find pivot element
// eg. a=[3,4,5,6,7,1,2]
// from 3 to 7, it is incresing graph. and after that again from 1 to 2 it is increasing. there are 2 increasing lines but a drop down in middle.
// in many places 7 is the pivot element and in many places 1 is pivot

// pivot element is that element where some change is happening.
// and pivot element > previous element && previous element > next element.

#include <iostream>
# include<vector>

using namespace std;


void findPivotElement1(vector<int> &v){ // linear serach - o(n)
  // traverse linearly-> since array in increasing order, find the point where 
  // a[i]>a[i+1], so i will be pivot

  for(int i=0;i<v.size()-1;i++){
    if(v[i]>v[i+1]){
      cout<<"[ linear o(n) ] pivot element is - "<<v[i]<<endl;
      break;
    }
  }

}

void findPivotElement2(vector<int> &v){ // linear serach - o(log n)

  int start = 0,end=v.size()-1,mid,pivot = -1;

  while(start<=end){

      mid = start + (end-start)/2;

      if(mid+1 < v.size() && v[mid]>v[mid+1]){ // handling case when mid is the pivot 
          pivot = v[mid];
          break;
      }

      if(mid-1 >=0 && v[mid] < v[mid-1]){ // handling case when mid-1 is the pivot
        pivot = v[mid-1];
        break;
      }

      if(v[0] > v[mid]) { // if start element > mid element --> search in left
        end = mid-1;
      }
      else // if start element <= mid eleent --> search in right
      {
        start = mid+1;
      }
  }

  cout<<"[ Binary Search o(log n) ] Pivot element is - "<<pivot<<endl;

}

int main() {
  
  vector<int> v{3,4,5,6,7,1,2};
  findPivotElement1(v);
  findPivotElement2(v);

  return 0;
}