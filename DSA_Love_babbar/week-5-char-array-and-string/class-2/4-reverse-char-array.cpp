#include <iostream>
#include<string.h>
using namespace std;


void reverse(char a[]){ // time complexity - o(n)
  int i=0,j=strlen(a)-1;
  while(i<=j){
    swap(a[i],a[j]);
    i++;
    j--;
  }

}


int main() {

  char a[6]={'m','u','k','e','s','h'};

  cout<<"character array - ";
  for(int i=0;i<strlen(a);i++) cout<<a[i];
  
  cout<<endl;
  
  reverse(a);

  cout<<"reverse character array - ";
  for(int i=0;i<strlen(a);i++) cout<<a[i];


  return 0;
}