
#include <iostream>
#include<string.h>
using namespace std;


bool string_compare(string a, string b){

  if(a.length() != b.length())
    return false;
  
  for(int i=0;i<a.length();i++){
    if(a[i] != b[i])
      return false;

  }

  return true;

}


int main() {
//--------------------------------------------------------------------
// string str ;
// // cin>>str;  //--> it can't take string with spaces

// getline(cin,str); // it can take string with spaces

// str[1]='\0';
// cout<<str<<endl;

// here this code will print complete line and replace only 1 index with space
//--------------------------------------------------------------------


//   char str[100];
//   cin.getline(str,50);

//   str[2]='\0';
// cout<<str;
// here this code will not print after index 2 and it will assume null character at index 2
//--------------------------------------------------------------------
string str = "mukesh";
cout<<str<<endl;

cout<<"length - "<<str.length()<<endl;
cout<<"is empty - "<< str.empty()<<endl;

str.push_back('A');
cout<<"push back - "<<str<<endl;

str.pop_back();
cout<<"pop back - "<<str<<endl;

// very important
cout<<"substr - "<<str.substr(1,3)<<endl; // from index 1, take 3 elements

string a = "mukesh negi";

if(str.compare(a) == 0) cout<<"string equal"<<endl;
else cout<<"string not equal"<<endl;


cout<<string_compare(str,a)<<endl;

string sentance = "hello how are you?";

cout<<"index of word - "<<sentance.find("how")<<endl;

// if element is not found, it gives garbage value

if(sentance.find("mm") == string::npos)
  cout<<"word not found in string"<<endl;
else
  cout<<"word found in string"<<endl;


// replace
sentance.replace(1,3,"kkkk"); // start with index 0 and replace the next 3elements 
cout<<"sentence after replace - "<<sentance<<endl;

sentance.erase(2,5); // earase 5 elements starting from index 2
cout<<"sentence after erase - "<<sentance<<endl;
  return 0;
}