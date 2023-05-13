#include <iostream>
using namespace std;

int main() {
  int a[4]={2,3,2,1};
  cout<<"integer array - ";
  for(auto x:a) cout<<x<<" ";
  cout<<endl;

  char b[4] = {'a','x','m','k'};
  cout<<"character array - ";
  for(auto x:b) cout<<x<<" ";
  cout<<endl;

  int c[4]={'a',4,'c', 5}; // here ascii value of character will store in the places; 
  // as int x = 'a'; --> it store the ascii of alphabel "a"
  for(auto x:c) cout<<x<<" ";
  cout<<endl;

// char -> 1 byte
// range -> -2^7 to 2^7 -1 
// unsinged -> 0 to 2^8-1

// int/char--> datatype
// array --> datastructure

// character array is data structure


  char ch[100];
  cout<<"Enter your name - "<<endl;
  cin>>ch;  // user will give mukesh, and it can take complete name in char array
  cout<<"your name is - "<<ch<<endl;

// store single single element in char array
  char m[100];
  m[0]='a';
  m[1] = 'b';
  cout<<"Enter one character - "<<endl;
  cin>>m[2];
  cout<<m[0]<<m[1]<<m[2]<<endl;



  // verify that null character is at last
  char name[100];
  cout<<"enter your name -"<<endl;
  cin>>name;
  for(int i=0;i<6;i++) cout<<"index - "<<i<<" value - "<<name[i]<<endl;


  // 7 is null
  int p = (int) name[7];
  cout<<p<<endl; // here zero shows that it is null character

  return 0;
}