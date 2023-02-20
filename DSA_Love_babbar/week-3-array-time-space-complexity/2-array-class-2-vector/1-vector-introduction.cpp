#include <iostream>
#include<vector>
using namespace std;


int main() {
  // vector--> dynamic array, which double its size as it gets full.
  // declare vector
  vector<int> a;
  cout<<"successfully created vector."<<endl;
  
  // crate vector at run time
  int n = 2;
  vector<int> d(n); // create vector of size n i.e. 2
  cout<<"vector at run time - "<<d[0]<<" "<<d[1]<<endl;
  
  // initialise
  vector<int> b{10,30,40};
  cout<<"vector initilise - "<<b[0]<<" "<<b[1]<<" "<<b[2]<<endl;

  vector<int> c(3,4); // crete vector of size 3 and all elements are 4
  cout<<"vector initilise with some values - "<<c[0]<<" "<<c[1]<<" "<<c[2]<<endl;
  
  // add elements
  c.push_back(5);
  cout<<"adding element 5 - "<<c[3]<<", size - "<<c.size()<<endl;
  
  // delete elements
  c.pop_back();
  cout<<"deleting element from last - size "<<c.size()<<endl;

  // check if vector is empty
  cout<<"is vector empty - "<<c.empty()<<endl;

  // size -> total elemtnes stored in vector
  //capacity --> total elements which vector can store.


  vector<int> k(10);// size is 10, capacity is 10, initially initialised by 0

  cout<<"vector k capacity before insert - "<<k.capacity()<<endl;
  k.push_back(4); // here intial size was 10, so when we inserted one element in vector, it doubled it's size to 20
  cout<<"Vector k capacity after insert - "<<k.capacity()<<", vector size is - "<<k.size()<<endl;


  return 0;
}