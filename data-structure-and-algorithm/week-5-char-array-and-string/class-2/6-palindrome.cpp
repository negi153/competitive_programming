// check if string is palindrome or not

#include <iostream>
#include<string.h>
using namespace std;


bool checkPalindrome(char name[]){ 
  // time -> o(n/2) --> o(n)
  // space -> o(1)

  int i=0,j=strlen(name)-1;

  while(i<=j){
    if(name[i] != name[j] )
      return false; // return false when corresponding elements are not equal
    
    i++;
    j--;
  }

  return true;
}



int main() {
  // Method -1 -basic approach --> create a new string which stores the reverse of the string.
  // check if string is equal to reverse or not.
  // time -> o(n)
  // space -> o(n)

  // Method 2 -> 2 pointers approach
  char name[100]={'n','a','m','a','k'};
  cout<<"Is name a prlindrome ? - "<<checkPalindrome(name)<<endl;

  return 0;
}