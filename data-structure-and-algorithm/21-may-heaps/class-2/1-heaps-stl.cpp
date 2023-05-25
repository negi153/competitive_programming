#include <iostream>
#include<queue>

using namespace std;

int main() {
  
  priority_queue<int> max_heaps; // this is max heap
  max_heaps.push(5);
  cout<<"max heap - "<<endl;
  cout<<"top - "<<max_heaps.top()<<endl;
  cout<<"size -"<<max_heaps.size()<<endl;

  max_heaps.pop();
  cout<<"is empty - "<<max_heaps.empty()<<endl;

  priority_queue<int, vector<int>, greater<int> > min_heap; // min heap
  min_heap.push(4);
  min_heap.push(5);
  cout<<"min heap - "<<endl;
  cout<<"top - "<<min_heap.top()<<endl;
  cout<<"size -"<<min_heap.size()<<endl;

  min_heap.pop();
  cout<<"is empty - "<<min_heap.empty()<<endl;



  return 0;
}