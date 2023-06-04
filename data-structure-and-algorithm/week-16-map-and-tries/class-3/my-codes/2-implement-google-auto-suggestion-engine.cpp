// google auto suggestion impletementation using trie
//hard question
// time-
    // insert -O(n*M)


#include <iostream>
#include<vector>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26]; // array to store the children
    bool isTerminal; // to identify if it is terminal or not
    int childCount;

    TrieNode(char d){
      this->data = d;
      for(int i=0;i<26;i++)
        children[i] = NULL;
    childCount=0;
      this->isTerminal = false;
    }
};


void insertWord(TrieNode* root, string word){
// cout<<"inserting "<<word<<endl;
    // base case
    if(word.length() == 0){ // if there is no word, then mark root as terminal
      root->isTerminal = true;
      return;
    }

    char ch = word[0];
    int index = ch-'a';
    TrieNode* child;

    if(root->children[index] != NULL){
      child = root->children[index];
    }
    else{
      // not present
      child = new TrieNode(ch);
      root->childCount++;
      root->children[index] = child;
    }

    insertWord(child,word.substr(1));

}

void storeSuggestions(TrieNode* curr, vector<string> & temp, string & prefix){

    if(curr->isTerminal){
      temp.push_back(prefix);
    }

    // a to z tak chooices
    for(char ch = 'a'; ch<='z';ch++){
        int index = ch - 'a';
        TrieNode* next = curr->children[index];

        if(next != NULL){ // if child exist
            prefix.push_back(ch);
            storeSuggestions(next,temp,prefix);
            prefix.pop_back();
        }

    }

}


vector<vector<string> > getSuggestions(TrieNode* root, string input){

    TrieNode* prev = root;
    vector<vector<string> > output;
    string prefix="";

    for(int i=0;i<input.length();i++){
      char lastch = input[i];
      int index = lastch - 'a';
      TrieNode* curr = prev->children[index];

      if(curr == NULL){
        break;
      }
      else{
        // create all child
        vector<string> temp; // it will store suggestions
        prefix.push_back(lastch);
        storeSuggestions(curr,temp, prefix);
        output.push_back(temp);
        prev=curr;
      }

    }

    return output;

}

int main() {
  TrieNode* root = new TrieNode('-');
  string arr[7] = {"love","lover","loving","lane","last","lost","lord"};

  string input = "lovi";

  for(auto x:arr)
    insertWord(root,x);

  vector<vector<string> > ans = getSuggestions(root,input);
  int i=0;
  string p="";
  for(auto x:ans){
    p+=input[i++];
    cout<<"suggestion for letter '"<<p<<"' - ";
    for(auto y:x)
      cout<<y<<" ";
    cout<<endl;
  }

  return 0;
}