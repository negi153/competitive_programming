#include <iostream>
#include<unordered_map>
using namespace std;

int main() {
  
  // creation
  unordered_map<string, int> m;

  // insertion
  pair<string,int> p = make_pair("scorpio",9);
  m.insert(p);

  pair<string,int> p2("alto",2);
  m.insert(p2);

  m["fortuner"] = 10;
  
  // access
  cout<<m.at("alto")<<endl;
  cout<<m["fortuner"]<<endl;

  // search
  cout<<"found ? - "<<m.count("Innova")<<endl; // if value preset then 1, other wise 0

  if(m.find("fortuner") != m.end()){
    cout<<"fortuner found"<<endl;
  }
  else{
    cout<<"fortuner not found "<<endl;
  }

  cout<<"size - "<<m.size()<<endl;
  cout<<m["abc"]<<endl;
  cout<<"size - "<<m.size()<<endl;

  // print map
  cout<<"showing elements - "<<endl;
  for(auto x:m)
    cout<<x.first<<" "<<x.second<<endl;
  return 0;
}