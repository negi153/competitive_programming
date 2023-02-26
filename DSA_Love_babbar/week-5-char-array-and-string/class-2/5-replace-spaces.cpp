#include <iostream>
#include<string.h>
using namespace std;


void replaceSpaces(char line[]){ // time --> o(n)

    for(int i=0;i<strlen(line);i++){
      if(line[i]==' ')
        line[i]='@';
    }

}


int main() {

  char line[100];
  
  cout<<"Enter full name with spaces - "<<endl;
  cin.getline(line,50); // 5o is the number of character which we want to input

  replaceSpaces(line);

  for(int i=0;i<strlen(line);i++) cout<<line[i];

  return 0;
}