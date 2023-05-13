#include <iostream>
#include<vector>

using namespace std;


int main() {
  
  vector<vector<int> > arr; // 2 D vector

  vector<int> a{1,2,3};
  vector<int> b{4,5,3,1,8};
  vector<int> c{1,9,3};

  arr.push_back(a);
  arr.push_back(b);
  arr.push_back(c);

  for(int i=0;i<arr.size();i++){
    for(int j=0;j<arr[i].size();j++)
      cout<<arr[i][j]<<" ";

    cout<<endl;
  }

  vector<vector<int> > d(3, vector<int>(5,0)); // vector rows-3, col-5 
cout<<endl;
// 0 0 0 0 0 
// 0 0 0 0 0 
// 0 0 0 0 0 
for(int i=0;i<d.size();i++){
    for(int j=0;j<d[i].size();j++)
      cout<<d[i][j]<<" ";

    cout<<endl;
  }

  return 0;
}