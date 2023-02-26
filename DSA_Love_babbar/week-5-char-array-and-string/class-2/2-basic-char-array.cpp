#include <iostream>
#include<string.h>

using namespace std;

int main() {
  // char name[100];
  // cout<<"enter you full name with space -"<<endl;
  // cin>>name; //give input as "mukesh singh negi"
  // cout<<name<<endl; // it only prints "mukesh"
  // why it only print first name before space---> because "cin" keyword can only read untill it come accross tab,space,new line character(\n, enter). so it only read before space

  char name1[100];
  cin.getline(name1,50); // arguments -> char array and max size, max size tells that maximum it can take 50 character as input
  // getline(cin,name1); // include string header for this
  cout<<name1;

  // we can pass 1 more argument in getline function, so we can tell compiler when to stop taking input which we call as delim(delimiter). by default it's enter

  return 0;
}