#include <iostream>
#include<queue>

using namespace std;

int getKthSmallest(int a[],int n,int k){

  // crete max heap
  priority_queue<int> pq;

  // insert first k elements
  for(int i=0;i<k;i++){
    pq.push(a[i]);
  }

  // for remaining element, push only if they are less than top
  for(int i=k;i<n;i++){

    if(a[i] < pq.top())
      {
        pq.pop();
        pq.push(a[i]);
      }

  }

  return pq.top();

}


int getKthGreatest(int a[],int n, int k){

  // crete min heap
  priority_queue<int,vector<int>,greater<int> > pq;

  // insert k elements in min heap
  for(int i=0;i<k;i++)
    pq.push(a[i]);

  // reminaing insert -> 
  for(int i=k;i<n;i++){
      if(a[i] > pq.top()){
        pq.pop();
        pq.push(a[i]);
      }
  }
  // min heap will contain top max k elements and top eleement will be the kth greatest
  return pq.top();
}

int main() {
  
  int a[] = {10,5,20,4,15};
  int n = 5;
  int k=2;

  int ans = getKthSmallest(a,n,k);
  cout<<"kth smallest - "<<ans<<endl;

  int ans1= getKthGreatest(a,n,k);
  cout<<"kth greatest - "<<ans1<<endl;

  return 0;
}