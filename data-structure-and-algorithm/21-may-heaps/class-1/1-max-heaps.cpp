#include<iostream>

using namespace std;


class Heap{
  public:
    int arr[101];
    int size;

    Heap(){
      size = 0;
    }

    void insert(int value){
      // increase size
      size = size + 1 ;
      int index = size;
      
      // insert element to last 
      arr[index] = value;

      // put this value to right position
      while(index > 1){
        int parentIndex = index/2;

        if(arr[index] > arr[parentIndex]){
            swap(arr[index] , arr[parentIndex]); // swap new element with parent
            index = parentIndex; // update current index
        }
        else{ // element is in correct place then break loop
            break;
        }
        
      }
      
    }

    int delete(int value){ // only delete root node(that is max value)
      
        int ans = arr[1]; // store maximum element of heap
      
        // replace root node with last node to delete root node
        arr[1] = arr[size];
        size--;

        //now place the root node on it's correct position (going from root to leaf)
        int index = 1;
        while(index < size){
          int leftIndex = 2*index; // left child
          int rightIndex = 2*index+1; // right child

          // find the index of elements among current node,left child, right child and replace with it
          int largestIndex = index; 

          if(leftIndex <=size && arr[leftIndex] > arr[largestIndex]){
            largestIndex = leftIndex;
          }

          if(rightIndex <=size && arr[rightIndex] > arr[largestIndex]){
            largestIndex = leftIndex;
          }

          if(largestIndex == index){
            // it's in correct position
            break;
          }
          else{
            swap(arr[largestIndex], arr[index]);
          index = largestIndex;
          }
          
        }

      return ans;
    }

    void heapify(int a[], int size, int index){

        int leftIndex = 2*index;
        int rightIndex = 2*index + 1;
        int largestIndex = index;

        if(leftIndex <= size && arr[leftIndex] > arr[largestIndex])
            largestIndex = leftIndex;

        if(rightIndex <= size && arr[rightIndex] > arr[largestIndex])
            largestIndex = rightIndex;

        if(largestIndex != Index){
          swap(arr[largestIndex], arr[index]);
          index = largestIndex;
          heapify(index); // recursion heapify
        }
        
    }


  void buildHeap(int a[],int n){
    for(int i=n/2;i>0;i--)
      {
        heapify(a,i);
      }
  }

  void heapsort(int a[],int n){
    
    while(n != 1){
      swap(a[1],a[n]); // max element went to last of array
      n--;
      heapify(a,n,1);
    }
    
  }

};

int main(){

  Heap h;
  h.arr[0]=-1;
  // input - 50 30 70 40 80 100 -1
  cout<<"Enter elements - ";
  int temp;
  cin>>temp;
  while(temp != -1){
    h.insert(temp);
    cin>>temp;
  }

  cout<<"show heap - ";
  for(int i=1;i<=h.size;i++){
    cout<<h.arr[i]<<" ";
  }

  cout<<endl;
  
  h.insert(110);

  cout<<"show heap - ";
  for(int i=1;i<=h.size;i++){
    cout<<h.arr[i]<<" ";
  }

  return 0;
}