logic 2- crete min heap and store first element of all the k sorted array in min heap. heap size will be k.
            the top of the  heap will be smallest so put that eleent in final_array and pop that and push next element of that array into heap.


#include <iostream>
#include<queue>
#include<vector>
using namespace std;


class info{

  public:
    int data;
    int row;
    int col;

    info(int val, int r, int c){
      data=val;
      row=r;
      col=c;
    }
};


class compare{
  public:
    bool operator()(info* a, info* b){
      return a->data > b->data;
    }
};


vector<int> mergeKSortedArray(int arr[][4],int k, int n){
  priority_queue<info*, vector<info*>, compare> minHeap;

  // insert first element of each array in min heap
  for(int i=0;i<k;i++){
    info* temp  = new info(arr[i][0],i,0);
    minHeap.push(temp);
  }

  vector<int> ans;

  while(!minHeap.empty()){ // untill heap is empty, insert value, row and col in heap
    info* temp = minHeap.top();
    int topElement = temp->data;
    int topRow = temp->row;
    int topCol = temp->col;

    minHeap.pop(); // pop top element

    ans.push_back(topElement); // pop min elelentin final array

    if(topCol + 1 < n){ // if element exist in same array, insert that in array
        topCol++;
        info* newInfo = new info(arr[topRow][topCol],topRow,topCol);
        minHeap.push(newInfo);
    }

  }

  return ans;

}

int main() {
  int arr[][4] = {{2,4,6,8},{1,3,5,7},{0,9,10,11}};
  int k=3;
  int n =4;

  vector<int> ans = mergeKSortedArray(arr,k,n);
  for(auto x:ans)
    cout<<x<<" ";
  
  cout<<endl;

  return 0;
}