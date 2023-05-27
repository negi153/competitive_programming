// https://leetcode.com/problems/find-median-from-data-stream/


#include <iostream>
#include<queue>
using namespace std;


void callMedian(int& median, priority_queue<int>& maxHeap,priority_queue<int,vector<int>,greater<int> >& minHeap, int element){
    // min heap is right half
    // max heap is left half
    
    if(minHeap.size() == maxHeap.size()){
        
        if(element > median){
          // push to right half --> minheap
          minHeap.push(element);
          median = minHeap.top();
        }
        else{
          maxHeap.push(element);
          median = maxHeap.top();
        }

      
    }
    else if(maxHeap.size() > minHeap.size()){
        // min heap is right half
    // max heap is left half
        if(element > median){
          minHeap.push(element);
          median = (minHeap.top() + maxHeap.top())/2;
        }
        else{
          int maxTop = maxHeap.top();
          maxHeap.pop();
          minHeap.push(maxTop);
          maxHeap.push(element);
          median=(minHeap.top()+maxHeap.top())/2;

        }
    } 
    else{ // min heap size is more than max heap
        // min heap is right half
    // max heap is left half
        if(element > median){
          int minTop = minHeap.top();
          minHeap.pop();
          maxHeap.push(minTop);
          minHeap.push(element);
          median = (minHeap.top() + maxHeap.top())/2;
        }
        else{
            maxHeap.push(element);
            median = (minHeap.top() + maxHeap.top())/2;
        }
    }
// cout<<element<<" "<<median<<" "<<minHeap.size()<<" " <<maxHeap.size()<<endl;
cout<<"inserting - "<<element<<", median - "<<median<<" "<<endl;
}


int main() {

  int arr[6]={5,7,2,9,3,8};
  int n=6;

  int median = 0;
  priority_queue<int> maxHeap;
  priority_queue<int,vector<int>,greater<int> > minHeap;

  for(int i=0;i<n;i++){
    int element = arr[i];
    callMedian(median, maxHeap, minHeap,element);
  }

  return 0;
}