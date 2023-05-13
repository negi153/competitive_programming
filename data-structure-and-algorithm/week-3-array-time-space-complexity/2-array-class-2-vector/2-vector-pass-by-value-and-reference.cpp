// Question -> given an array, having every element coming as twice, except only one element which comes single time. find that element.

#include <iostream>
#include<vector>
using namespace std;

// vector uses pass by reference, to pass it as pass by reference use below syntax
void pass_by_reference(vector<int> &a){
  cout<<"size in pass by reference functin before adding element - "<<a.size()<<endl;
  a.push_back(8);
  cout<<"size in pass by reference functin after adding element - "<<a.size()<<endl;

}

void pass_by_value(vector<int> a){
  
  cout<<"size in pass by value functin before adding element - "<<a.size()<<endl;
  a.push_back(8); // adding element in copy vector which gives 13
  cout<<"size in pass by value functin after adding element - "<<a.size()<<endl;

}

int main() {

  vector<int> a{2,3,2,3,1,1,4,5,6,5,6}; //initial size - 11

  pass_by_value(a); //here we are passing vector as a copy which is pass by value
  cout<<"size in main functin after adding element - "<<a.size()<<endl;

  pass_by_reference(a); // here we are passing vector as a pointer which is pass by reference
  cout<<"size in main functin after adding element - "<<a.size()<<endl;


  return 0;
}