#include <iostream>
using namespace std;


void row_sum(int a[][100], int row, int col){  // need to give last bracket value for 2-D array

cout<<"method -";

for(int i=0;i<row;i++){
    int s=0;
    for(int j=0;j<col;j++){
      s+=a[i][j];
    }
    cout<<s<<" ";
  }


}

// sum or rows in 2-D array
int main() {
  
  int a[100][100];
  int row,col; cin>>row>>col;

  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      cin>>a[i][j];
    }
  }

  for(int i=0;i<row;i++){
    int s=0;
    for(int j=0;j<col;j++){
      s+=a[i][j];
    }
    cout<<s<<" ";
  }
  cout<<endl;
  row_sum(a,row,col);

  return 0;
}