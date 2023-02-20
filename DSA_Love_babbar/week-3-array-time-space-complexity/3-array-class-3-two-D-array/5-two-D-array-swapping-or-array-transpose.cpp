#include <iostream>
using namespace std;


void transpose(int a[][100],int row, int col){
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      if(i<=j)  // this condition will prevent from double swapping eg. it was swapping when i=0,j=1 and also swapping i=1,j=0, so we were getting original array
      // to prevent this we are only swapping half of the array
      swap(a[i][j],a[j][i]);
    }
  }

  cout<<"print transpose array -"<<endl;
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
}


void transposeMethod2(int a[][100],int row, int col,int transposeArr[][100]){
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      transposeArr[j][i] = a[i][j]; // store array value in transpose position
    }
  }

  cout<<"print transpose array by storing in another array -"<<endl;
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      cout<<transposeArr[i][j]<<" ";
    }
    cout<<endl;
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

  // transpose(a,row,col);
  cout<<endl;

  int transposeArr[100][100];
  transposeMethod2(a,row,col,transposeArr);

  return 0;
}