#include <iostream>
using namespace std;


void col_sum(int a[][100], int row, int col){  // need to give last bracket value for 2-D array

cout<<"col sum -";

for(int i=0;i<row;i++){
    int s=0;
    for(int j=0;j<col;j++){
      s+=a[j][i];   // interchange i and j to traverse column wise
    }
    cout<<s<<" ";
  }

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

  col_sum(a,row,col);

  return 0;
}