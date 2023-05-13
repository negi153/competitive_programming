#include <iostream>
using namespace std;

int last_occurance_of_character1(string s, char ch){
   // time o(n), space -> o(1) // iterative solution from left to right
  int index = -1;
  for(int i=0;i<s.length();i++){
    if(s[i]==ch)
      index = i;
  }

  return index;
}

int last_occurance_of_character2(string s, char ch){

  // time o(n), space -> o(1) iterative solution from right to left

  for(int i=s.length()-1;i>=0;i--){
    if(s[i]==ch)
      return i;
  }

  return -1;
}


int last_occrance_recursive(string s,int cur_index, char ch){
   // time - o(n) [[ traversion each element from right to left]] , space -- o(n) [[ stack memory in recursion call]]

  if(cur_index < 0) // if cur_index goes below 0 , then element not found
    return -1;

  if(s[cur_index] == ch) // if element found, return current index
    return cur_index;

  return last_occrance_recursive(s,cur_index-1,ch); // if current element is not matching, then check previous element recursively

}

int last_occrance_recursive_forward(string s,int cur_index, char ch){
// time - o(n) [[ traversion each element from left to right]] , space -- o(n) [[ stack memory in recursion call]]

  if(cur_index >= s.length()) // if cur_index >= length of string , then element not found
    return -1;

  int index = last_occrance_recursive_forward(s,cur_index+1,ch); // find element in next elements

  if(index != -1) // if element found in next elements
    return index;
  else if(s[cur_index] == ch) // if element not found in next elements and current element is matcing, return current index
    return cur_index;
  else
    return -1;

}

void last_occurance(string& s, char ch, int cur_index, int& ans){
  // passing answer variable as reference pointer
// time - o(n) [[ traversion each element from left to right]] , space -- o(n) [[ stack memory in recursion call]]

  if(cur_index >= s.size())
    return;

  if(s[cur_index] == ch)
    ans = cur_index;

  last_occurance(s,ch,cur_index+1,ans);

}

int main() {
  
  // abcdddedf
  // 012345678

  string s = "abcdddedf";
  char ch ='d';

  cout<<"forward iterate - "<<last_occurance_of_character1(s,ch)<<endl; // forward iterate

  cout<<"backward iterate - "<<last_occurance_of_character2(s,ch)<<endl; // backward iterate

  cout<<"recursive function forward - "<<last_occrance_recursive_forward(s,0,'k')<<endl; // recursive method forward

  cout<<"recursive function backward - "<<last_occrance_recursive(s,s.length()-1,'k')<<endl; // recursive method backward

  // find answer by reference pointer
  int ans = -1;
  last_occurance(s,ch,0,ans);
  cout<<"recursive reference pointer - "<<ans<<endl;
  return 0;
}