#include <iostream>
#include<vector>
using namespace std;

void find_unique_element_1(vector<int> &a){
  // brute force - o(n^2)
  
  for(int i=0;i<a.size();i++){
    
    bool found_unique = true;

    for(int j=i+1;j<a.size();j++)
    {
      if(a[i] == a[j]){
        found_unique = false;
        break;
      }
    }

    if(found_unique)
      {
        cout<<"unique element in vector - "<<a[i]<<endl;
        break;
      }
  }

}

void find_unique_element_1(vector<int> &a){

}

int main() {
    
    vector<int> a{2,3,2,3,1,1,4,5,6,5,6}; 

    find_unique_element_1(a);

  return 0;
}