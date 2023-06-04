#include <iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26]; // array to store the children
    bool isTerminal; // to identify if it is terminal or not

    TrieNode(char d){
      this->data = d;
      for(int i=0;i<26;i++)
        children[i] = NULL;
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
      root->children[index] = child;
    }

    insertWord(child,word.substr(1));

}


bool searchWord(TrieNode* root, string word){
    // base case -> when there is no word to sear, check if root is terminal or not
    if(word.length() == 0){
      return root->isTerminal;
    }

    char ch = word[0];
    int index = ch-'a';
    TrieNode* child;

    // present
    if(root->children[index] != NULL){
      child = root->children[index];
    }
    else{
      // not present
      return false;
    }

    return searchWord(child,word.substr(1));

}

void deleteWord(TrieNode* root, string word){

    if(word.length()==0){
      root->isTerminal=false;
      return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    // present
    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{ // not preesnt
      return;
    }

    deleteWord(child, word.substr(1));

}


int main() {
  
  TrieNode* root = new TrieNode('-');
  insertWord(root, "coding");
  insertWord(root, "code");
  insertWord(root, "coder");
  insertWord(root, "codehelp");
  insertWord(root, "baba");
  insertWord(root, "baby");
  insertWord(root, "babu");
  insertWord(root, "shona");

  string findWord = "code";
  if(searchWord(root,findWord)){
    cout<<findWord<<" present"<<endl;
  }
  else{
    cout<<findWord<<" absent"<<endl;
  }

  deleteWord(root, "code");

  if(searchWord(root,"code")){
    cout<<"code present"<<endl;
  }
  else{
    cout<<"code absent"<<endl;
  }

  return 0;
}
