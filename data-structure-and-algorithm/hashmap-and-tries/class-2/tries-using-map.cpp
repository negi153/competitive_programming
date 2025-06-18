#include <iostream>
#include<unordered_map> 
using namespace std;


class TrieNode{
        public:
        unordered_map<char,TrieNode*> childs;
        bool isTerminal;
        char data;
        
        TrieNode(char d) {
            this->data = d;
            this->isTerminal = false;
        }
};

void insert(TrieNode* root, string word) {
        //cout << "Inserting " << word << endl;
   //base case
        if(word.length() == 0) {
                root->isTerminal = true;
                return;
        }
        
        char ch = word[0];
        
        TrieNode* child;
        
        //present
        if(root->childs.count(ch)) {
                child = root->childs[ch];
        }
        else {
                //not present
                child = new TrieNode(ch);
                root->childs[ch] = child;
        }

        //recursion sambhal lega
        insert(child, word.substr(1));
}

bool search(TrieNode* root, string word) {
        //base case
        if(word.length() == 0) {
                return root->isTerminal;
        }

        char ch = word[0];
        
        TrieNode* child;

        //present
        if(root->childs.count(ch)) {
                child = root->childs[ch];
        }
        else{
                return false;
        }
        //rec call
        return search(child, word.substr(1));

}


string deleteNode(TrieNode* root, string word) {
        //base case
        if(word.length() == 0) {
            if (root->isTerminal == false)
                return "word doesn't exits";
            else{
                root->isTerminal = false;
                return "word deleted";
            }
        }

        char ch = word[0];
        TrieNode* child;

        //present
        if(root->childs.count(ch)) {
                child = root->childs[ch];
        }
        else{
                return "word doesn't exist";
        }
        //rec call
        return deleteNode(child, word.substr(1));

}
int main() {

   TrieNode* root = new TrieNode('-');

   // insert
   insert(root,"mukesh");
   insert(root,"munni");
   insert(root,"mukta");

   // search
   cout<<"search mukesh - "<<search(root,"mukesh")<<endl;
   cout<<"search munni - "<<search(root,"munni")<<endl;
   cout<<"search mukta - "<<search(root,"mukta")<<endl;
   cout<<"search ankita - "<<search(root,"ankita")<<endl;
   cout<<"search nikita - "<<search(root,"nikita")<<endl;
   
   cout<<"deleting mukesh : "<<deleteNode(root,"mukesh")<<endl;
   cout<<"deleting mukesh : "<<deleteNode(root,"mukesh")<<endl;
   cout<<"deleting rahul : "<<deleteNode(root,"rahul")<<endl;
   cout<<"search mukesh : "<<search(root,"mukesh")<<endl;

  return 0;
}