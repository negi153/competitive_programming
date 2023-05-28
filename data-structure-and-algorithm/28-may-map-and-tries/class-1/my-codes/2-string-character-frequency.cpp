#include <iostream>
#include<unordered_map>
using namespace std;

int main() {
  
  // creation
  unordered_map<char, int> m;

  string s="aabbbbccc";

  for(int i=0;i<s.length();i++){
    m[s[i]]++;
  }

  for(auto x:m){
    cout<<x.first<<" "<<x.second<<endl;
  }
  
  return 0;
}