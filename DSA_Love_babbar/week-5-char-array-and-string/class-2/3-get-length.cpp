#include <iostream>
#include<string.h>
using namespace std;

int getLength(char name[]){
  int i=0,length = 0;

  while(name[i]!='\0'){
    i++;
    length++;
  }

  return length;
}

int main() {
  // char name[100];
  // cin>>name;

  // cout<<"length is : "<<getLength(name)<<endl;
  // cout<<"length functin - "<<strlen(name)<<endl;

  char name1[100];
  cin.getline(name1,50);
  cout<<"length is : "<<getLength(name1)<<endl;
  cout<<"length function - "<<strlen(name1)<<endl;

  return 0;
}