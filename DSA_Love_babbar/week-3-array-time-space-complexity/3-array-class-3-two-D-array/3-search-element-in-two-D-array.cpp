#include <iostream>
using namespace std;


bool find_element(int a[][100], int row, int col,int key){  // need to give last bracket value for 2-D array

for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      if(a[i][j] == key)
        return true;
    }
  }
return false;
}

// sum or rows in 2-D array
int main() {
  
  int a[100][100];
  int row,col; cin>>row>>col;

  for(int i=0;i<row;i++){
    int s=0;
    for(int j=0;j<col;j++){
      cin>>a[i][j];
    }
  }

  int key = 5;
if(find_element(a,row,col,key)) cout<<"present";
else cout<<"not present";

  return 0;
}