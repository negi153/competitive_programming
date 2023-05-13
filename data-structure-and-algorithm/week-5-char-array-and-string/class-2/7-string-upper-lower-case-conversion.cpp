
#include <iostream>
#include<string.h>
using namespace std;

void convert_to_upper_case(char name[]){

  // time -> o(n)

  // ASCII of "A" -> 65
  // ASCII of "a" -> 97
  // to convert form lower to upper, we need to subtract 32 

  for(int i=0;i<strlen(name);i++){
    char x = name[i]-32;
    name[i]=x;
  }


}

void convert_to_upper_case1(char name[]){

  // time -> o(n)
  // subtract 'a' from character and then add "A" to convert it into upper character
  // eg. character is "c" --> c - a + A  --> 99 - 97 + 65 --> 67 ---> C
  for(int i=0;i<strlen(name);i++){
    name[i] = name[i] - 'a' + 'A';
  }


}

void convert_to_lower_case(char name[]){

  // time -> o(n)

  // ASCII of "A" -> 65
  // ASCII of "a" -> 97
  // to convert form upper to lower, we need to add 32 

  for(int i=0;i<strlen(name);i++){
    char x = name[i]+32;
    name[i]=x;
  }


}

void convert_to_lower_case1(char name[]){

  // time -> o(n)

  // subtract 'A' from character and then add "a" to convert it into upper character
  // eg. character is "C" --> C - A + a  --> 67 - 65 + 97 --> 99 ---> c

  for(int i=0;i<strlen(name);i++){
    name[i]=name[i]-'A'+'a';
  }


}

int main() {
  
  char name[100]={'m','u','k','e','s','h'};

  cout<<"original char array - "<<name<<endl;

  cout<<"method 1 -----"<<endl;
  convert_to_upper_case(name);
  cout<<"Upper case - "<<name<<endl;

  convert_to_lower_case(name);
  cout<<"lower case - "<<name<<endl;
  
  ////////////////////////////////////////////////////
  // Method 2
  ///////////////////////////////////////////////////
  
  cout<<"method 2 -----"<<endl;

  convert_to_upper_case1(name);
  cout<<"Upper case - "<<name<<endl;

  convert_to_lower_case1(name);
  cout<<"lower case - "<<name<<endl;


  return 0;
}