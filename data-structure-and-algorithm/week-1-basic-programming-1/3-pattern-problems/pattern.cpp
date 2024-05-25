#include <iostream>
using namespace std;

void pyramid(){
    // * 
    // * * 
    // * * * 
    // * * * * 
    // * * * * * 

    int n = 5;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
            cout<<"* ";
        cout<<endl;
    }
}


void inverted_pyramid(){
  // * * * * * 
  // * * * * 
  // * * * 
  // * * 
  // *
  cout<<endl;
  int n=5;
  for(int i=0;i<n;i++){
    for(int j=0;j<n-i;j++)
      cout<<"* ";
    cout<<endl;
  }
}


void numric_half_pyramid(){

  // 1 
  // 1 2 
  // 1 2 3 
  // 1 2 3 4 
  // 1 2 3 4 5 

  cout<<endl;

  int n=5;

  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++)
      cout<<j<<" ";

    cout<<endl;
  }

}

void inverted_half_pyramid(){
    // 1 2 3 4 5 
    // 1 2 3 4 
    // 1 2 3 
    // 1 2 
    // 1 
    cout<<endl;

    int n=5;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++)
        cout<<j<<" ";

        cout<<endl;
    }

}

int main(){


  pyramid();

  inverted_pyramid();

  numric_half_pyramid();

  inverted_half_pyramid();

  return 0;
}