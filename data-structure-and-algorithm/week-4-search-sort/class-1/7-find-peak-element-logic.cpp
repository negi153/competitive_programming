// find peak element in an array.
// a    = [1,2,3,4,3,3,1,0]
//index = [0,1,2,3,4,5,6,7]
// here peak element is 4. initially elements will be increasing order (from 1 to 4) and then they will be in decreasing order(4 to 0).

#include <iostream>
#include<vector>
# include<algorithm>
# include<limits.h>
using namespace std;


void find_peak_element1(vector<int> & v){ 
  // logic --> iterate in vector and find the maximum element because peak element will be maximum in array
  // time complexity - o(n)

  int maxy = INT_MIN;
  for(int i=0;i<v.size();i++){ // traverse on each element
    if(v[i]>maxy) // if element is more than maximum element then update it
      maxy = v[i];
  }

  cout<<"[ Linear traversal o(n) ] Peak/maximum element is - "<<maxy<<endl;

}


void find_peak_element2(vector<int> & v){ // time complexity - o(n)
  // logic -> peak element will always be >= it's previous element and after element.  a[i-1] <= a[i] >= a[i+1]
  // assumption, that there will always be peak/ there will always line increase first and then decrease.
  // assumption - means a[0] && a[n-1] will never be peak element

    for(int i=1;i<v.size()-1;i++){
      
      if(v[i]>=v[i-1] && v[i]>=v[i+1]){
        cout<<"[ Linear traversal o(n) ] Peak/maximum element is - "<<v[i]<<endl;
        break;
      }


    }



}


void find_peak_element3(vector<int> & v){ // time complexity-o(log n)
  // logic -> 
  // peak element > previous element and after element i.e a[i] > a[i-1] && a[i]> a[i+1]

  // here we will compare wid element with its next element
  // if mid element > element after mid i.e mid+1  ==> i.e a[mid]>a[mid+1]:
  //     that means it is decreasing line. so answer will be in left direction.
  //     but here we will not do end=mid-1. because mid can also be peak as a[mid] 
  //     may be less than a[mi-1].
          // store mid as peak element

  //     end = mid 
  
  // else if mid element < next element --> if mid < a[mid+1]:
  //     then we are in increasing line, and since mid is less then mid can't be a peak. so here below condition will satisfy

  //     start = mid+1

  int start = 0, end = v.size()-1, mid, peak;

  while(start<end){ // as we are storing end = mid in 1 condition, so if we use equality then it will stuck in infinite loop
      // eg. start = 3, end = 3, mid = 3, and when if condition satisfy then end 
      //will be mid =3 again. and start willl never become > end
      // so removed equality

    mid = start + (end - start)/2;

    if(v[mid] > v[mid+1]){ // we are in decreasing line
        end = mid; // find element in back side
        peak = v[mid]; // store it peak for now
    }
    else if (v[mid]<v[mid+1]){ // we are in incresing line
      start = mid+1;
    }

  }

  cout<<"[ Binary traversal o(log n) ] Peak element - "<<peak<<", index - "<<start<<endl;

  // here we are using index as start why?
  // loop will break when start == end
  // because there will be a point where start and end willl point on same element
  // that will be the anwer so we can use start or end

}

int main() {
  //input
  vector<int> v{1,2,3,4,3,3,1,0};
  
  find_peak_element1(v); // linear traversal
  find_peak_element2(v); // linear traversal
  find_peak_element3(v); // binary traversal

  return 0;
}