#include <iostream>
#include<limits.h> // for INT_MAX / INT_MIN
using namespace std;


int find_max(int a[][100], int row, int col){  // need to give last bracket value for 2-D array

int maxy=INT_MIN;
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      if(a[i][j] > maxy)
        maxy=a[i][j];
    }
  }
return maxy;
}


int find_min(int a[][100], int row, int col){  // need to give last bracket value for 2-D array

int mini=INT_MAX;
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      if(a[i][j] < mini)
        mini=a[i][j];
    }
  }
return mini;
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

  cout<<"maximum - "<<find_max(a,row,col)<<endl;
  cout<<"minimum - "<<find_min(a,row,col);

  return 0;
}