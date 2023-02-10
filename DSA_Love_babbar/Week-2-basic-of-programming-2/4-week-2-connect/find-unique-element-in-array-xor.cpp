#include <iostream>
using namespace std;

// a array contains every element 2 times, except one element which is coming
// only 1 time.find the unique element eg. 1,2,3,4,4,1,2 here only 3 is coming 1
// time so answer is 3
// logic --> xor of same element gives 0
// 1 ^ 2 ^ 3 ^ 4 ^ 4^ 1 ^ 2
// duplicate element cancel out each other and only unique element will left.
// for multiple unique elements it will give answer of xor of those multiple
// unique elemets. but it  will not unique elemtn.

//basic approach --> o(n^2)
void method1(){

  int n = 7;
  int a[7] = {1, 2, 3, 4, 4, 1, 2};
  
  for(int i=0;i<n;i++){
    
    int is_duplicate_present = false;
    
    for(int j=i+1;j<n;j++){
      
      if(a[i]==a[j]){
        is_duplicate_present = true;
        break;
      }
    }

      if(is_duplicate_present == false){
        cout<<"Unique element is "<<a[i];
        break;
      }
  }

  cout << "final ans " << ans;
}

// mid approac --> o(nlogn)
void method2(){

  // int n = 7;
  // int a[7] = {1, 2, 3, 4, 4, 1, 2};
  
  // sort array in nlogn

  //iterate in array and compare adjacent elements.
  //if duplicate is not present in adjacent, then that is unique element

}

// using xor --> o(n)
void method3(){

  int n = 7;
  int a[7] = {1, 2, 3, 4, 4, 1, 2};
  
  int ans = a[0];
  for (int i = 1; i < n; i++) {
    cout << ans << " ^ " << a[i] << " -> ";
    ans = ans ^ a[i];
    cout << ans << endl;
  }

  cout << "final ans " << ans;
}

int main() {
  

  method1();
  method2();
  method3();

  return 0;
}
