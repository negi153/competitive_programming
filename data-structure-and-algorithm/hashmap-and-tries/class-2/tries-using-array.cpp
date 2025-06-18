#include<iostream>

using namespace std;

class TrieNode{
   public:
   char data;
   bool isTerminal;
   TrieNode* children[26];

   TrieNode(char c){
       this->data = c;
       this->isTerminal=false;
       for(int i=0;i<26;i++)
           this->children[i]=NULL;
   }
};


void insert(TrieNode* root,string word){
   //base case
   if (word.length()==0)
   {
       root->isTerminal=true;
       return;
   }

   // find position of children
   int index = word[0]-'a';

   // if children at a particular index is not null, that means it's present
   TrieNode* child;
   if (root->children[index] != NULL){
       child = root->children[index];
   }
   else{ // children at particular index is null, means it's not present,so create children
       child = new TrieNode(word[0]);
       root->children[index] = child;
   }

   // add next characters of string using recursion
   insert(child,word.substr(1));

}


bool search(TrieNode* root,string word){
   // base cae
   if (word.length() == 0){
       return root->isTerminal;
   }


   // find position of children
   int index = word[0]-'a';

   // if children at a particular index is not null, that means it's present
   TrieNode* child;
   if (root->children[index] != NULL){
       child = root->children[index];
   }
   else{ // children at particular index is null, means it's not present,so string not present
       return false;
   }

   // search by recursion
   return search(child,word.substr(1));
}

string deleteNode(TrieNode* root, string word){
   
   // base
   if (word.length() ==0 ){
       // delete string from trie by marking termianl aas false
       if (root->isTerminal == true){
           root->isTerminal = false;
           return "Deleted";
       }
       else
           return "Element doesn't exist";
           
   }
   
   
   // cout<<"deleting "<<word<<endl;
   char c = word[0];
   int index = c-'a';
   TrieNode* child;
   
   if (root->children[index] != NULL){
       child = root->children[index];
   }
   else{
       return "Element doesn't exist";
   }
   
   return deleteNode(child,word.substr(1));
}

int main(){

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