// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

class heap{
    
    public:
        vector<int> arr = {-1};
        int len = 0;
        
        void insert(int n){
            arr.push_back(n);
            len++;
            
            // update it to it's correct position
            int index = len;
            while(index > 1){
                int parent = index/2;
                if(arr[parent] < arr[index]){
                    swap(arr[parent],arr[index]);
                    index = parent;
                }
                else
                    break;
            }
        }
        
        void deleteMax(){
            // replalce 
            arr[1] = arr[len];
            len--;
            
            int index = 1;
            while(index <= len){
                int left = 2*index;
                int right = 2*index+1;
                int largestIndex = index;
                
                if(left <= len && arr[largestIndex] < arr[left]){
                    largestIndex = left;
                }
                
                if(right <= len && arr[largestIndex] < arr[right]){
                    largestIndex = right;
                }
                
                if(arr[largestIndex] != arr[index]){
                    swap(arr[index],arr[largestIndex]);
                    index= largestIndex;
                }
                else{
                    break;
                }
                
            }
            
            
        }
        
        void print(){
            cout<<"numbeer of elemetn in heap - "<<len<<endl;
            for(auto x:arr)
                cout<<x<<" ";
                
            cout<<endl;
        }

};

void heapify(vector<int>& data, int curr, int n){
    int left = 2*curr;
    int right = 2*curr+1;
    int largestIndex = curr;
    
    if(left <= n && data[left] > data[largestIndex]){
        largestIndex = left;
    }
    
    if(right <= n && data[right] > data[largestIndex]){
        largestIndex = right;
    }
    
    if(curr != largestIndex){
        swap(data[largestIndex],data[curr]);
        heapify(data,largestIndex,n);
    }
}

void build_heap(vector<int>& data, int n){
    // apply heapify on non leaf nodes
    for(int i = n/2;i>=1;i--){
        heapify(data,i,n);
    }
}


void heap_sort(vector<int>& data, int n){
    // swap max element with the last and apply heapify
    
    int i = n;
    while(i>1){
        swap(data[1],data[i]);
        n--;
        
        heapify(data,1,n);
        i--;
    }
}

int main() {
    
    heap h;
    h.insert(3);
    h.insert(7);
    h.insert(18);
    h.insert(12);
    h.insert(8);
    h.insert(9);
    h.insert(6);
    // h.insert(50);
    
    h.print();
    
    h.deleteMax(); // delete top max elelent
    h.print();
    
    cout<<"build heap"<<endl;
    vector<int> data = {-1, 5,3,4,2,6,7};
    int n = 6;
    build_heap(data,n);
    
    cout<<"printing heap - "<<endl;
    for(auto x: data) cout<<x<<" ";
    cout<<endl;
    
    cout<<"heap sorting - ";
    heap_sort(data,n);
    for(auto x: data) cout<<x<<" ";
    cout<<endl;
    
    
    

    return 0;
}