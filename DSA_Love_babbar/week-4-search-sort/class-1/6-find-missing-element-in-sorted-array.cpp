// find misssing number in sorted array. vector contains number from 1 to n in sorted way. and one number is missing in array. find that number.
// a    = [1,2,3,4,6,7,8,9]
//index = [0,1,2,3,4,5,6,7]
// missing number = 5

#include <iostream>
#include<vector>
# include<algorithm>


using namespace std;


void find_missing_number1(vector<int> &v,int n){ // time complexity -> o(n^2)
  // logic -> for all numbers from 1 to n check if that numbeer is present in vector or not by linear search.

    for(int number=1;number<n;number++){ // iterate on each number from 1 to n;

        bool is_num_present = false; // assume if number is present in vector
        for(int j=0;j<v.size();j++){ // check in vector if element is present or not.
          if(number == v[j]){
            is_num_present = true; // mark that number is present
            break; // break if number is present
          }
        }

        if(is_num_present == false) // if number is not present in vector
        {
          cout<<"[ Brute force o(n^2) ] missing number is - "<<number<<endl;
          break; // break when we found missing number
        }
    }
}

void find_missing_number2(vector<int> &v,int n){ // time complexity -> o(n*logn)
  // logic -> for all numbers from 1 to n check if that numbeer is present in vector or not by binary search since vector is in sorted order.

    for(int number=1;number<n;number++){ // iterate on each number from 1 to n;

        if(! binary_search(v.begin(),v.end(),number)) // if number is not present in vector
        {
          cout<<"[ Binary search inside linear search o(n*logn) ] missing number is - "<<number<<endl;
          break;
        }

    }
}

void find_missing_number3(vector<int> &v,int n){ // time complexity -> o(n)
  // logic -> find the sum of n numbers by the formuls (n*(n+1))/2, then find the sum of numbers in vector and their difference will be the missing number

    int sum = 0;
    for(int i=0;i<n;i++){ // iterate on each element of vector
      sum+=v[i];
    }

    int sum_of_n_numbers = (n*(n+1))/2;

    cout<<"[ Linear traversal o(n)] missing number - "<<sum_of_n_numbers - sum<<endl;
}

void find_missing_number4(vector<int> &v,int n){ // time complexity -> o(log n)
  // logic -> 
    // v     = [1,2,3,4,6,7,8,9]
    // index = [0,1,2,3,4,5,6,7]

    // here, if we look between index 0 to 3, element is index+1
    // and between index 4 to 7, element is index+2 which is representing monotonic in nature.

    // by using binary search -
    //   if v[mid] == index + 2
    //     that means, mid element may be a possible solution  for missing element, so store it. and look into left which may have the correct answer 
    //   else if v[mid] == index + 1:
    //     that means, till mid element pattern is following (which means element is not missing till mid element) so don't look into left, check in right direction
    
    int start = 0, end = v.size()-1,mid,missing_element;

    while(start <= end){
      mid = start + (end - start)/2; // find mid element

      if(v[mid] == mid + 2) // if mid element is index + 2
      {
        missing_element = v[mid]; // store the possible candidate for missing element
        end = mid - 1; // since mid is possible candidate, so actual missing may be preesnt in left, so go in left direction
      }
      else if(v[mid] == mid + 1) // if mid element is index +1
      {
        // that measn till mid no element is missing so check in right direction
        start = mid + 1;
      }
    } 

    // at the end of the loop, missing_element will have the number which comes just after the missing element (where this pattern (element = index + 2) starts ), so missing element will be 1 less. i.e (missing_element -1 )
    
    cout<<"[ Binary search o(log n)] missing number - "<<missing_element - 1<<endl;
}
int main() {
  //input
  vector<int> v{1,2,3,4,6,7,8,9};
  int n = 9;

  find_missing_number1(v,n); // brute force approach
  find_missing_number2(v,n); // binary search inside linear search
  find_missing_number3(v,n); // linear traversal
  find_missing_number4(v,n); // binary search
  return 0;
}