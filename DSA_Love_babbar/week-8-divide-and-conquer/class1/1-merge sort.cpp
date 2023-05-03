#include <iostream>
using namespace std;

// time complexity --> nlogn
// T(n) = 2 * T(n/2) [[ left and right call recursion ]] + n * k [[ merge complexity ]]

// finding time complexity
// T(n) = T(n/2) + n*k
// T(n/2) = T(n/4) + n*k/2
// T(n/4) = T(n/8) + n*k/4
// .......................
// .......................
// T(1) = k
// ------------------------------
// T(n) = n*k + n*k/2 + n*k/4 + .......+1
//       = k* (n + n/2 + n/4 + ......+ 1)     here lets assume n/(2^m) = 1  where m is total number of steps--> n=2^m --> log n = log (2^m) ---> m = logn  
//       = k* n * m = k* n* log n 
//       = nlogn

// -------------------------------

void merge_sorted_arrays(int a[],int s, int e){

  int mid = (s+e)/2;
  int array_length = e-s+1;

  int* sorted_array = new int[array_length];

  int i = s; // point to starting of first half
  int j = mid+1; // point to starting of second half
  int k=0; // point to start of result sorted array

  // sorting left half and right half
  while(i <= mid && j <= e){
    if(a[i] <= a[j])
        sorted_array[k++] = a[i++];
    else
        sorted_array[k++] = a[j++];
  }


  // copy left half elements
  while(i <= mid)
    sorted_array[k++] = a[i++];

  //copy right half elements
  while(j <= e)
    sorted_array[k++] = a[j++];

  // replacing sorted values in original array
  k = 0;
  for(int i=s;i<=e;i++) 
      a[i] = sorted_array[k++]; 

  // cout<<"s = "<<s<<" e = "<<e<<" mid = "<<mid<<" - ";
  // for(int i=s;i<=e;i++) cout<<a[i];
  // cout<<endl;
  
}

void merge_sort(int a[],int s, int e){

  if (s >= e) return; // if array contains only one element then it is already in sorted order

  int mid = (s+e)/2;

  merge_sort(a,s,mid); // sort left  half

  merge_sort(a,mid+1,e); // sort right half

  merge_sorted_arrays(a,s,e); // merge two sorted array

}

int main() {
  int a[] = {3,2,1,9,3,5,4};
  int n = 7;

  cout<<"Initial array - ";
  for(int i=0;i<n;i++) cout<<a[i]<<" ";

  cout<<endl;

  merge_sort(a,0,n-1);

  cout<<"merged sort - ";
  for(int i=0;i<n;i++) cout<<a[i]<<" ";

  return 0;
}