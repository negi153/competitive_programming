https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

#include<iostream>
#include<queue>

using namespace std;

// node class
class node{
  public:
    int data;
    node* left = NULL;
    node* right = NULL;

  node(int data){
    this->data = data;
  }
};

void levelOrderTraversal(node* root){

  queue<node*> q;
  q.push(root);
  q.push(NULL);

  while(!q.empty()){
    node* cur = q.front();
    q.pop();

    if(cur == NULL){ // means level ended here
      cout<<endl; // change the line

      if(!q.empty()) // if q is not empty then insert NULL to tell that level ending here
          q.push(NULL);

      continue;
    }
    cout<<cur->data<<" ";

    if(cur->left)
        q.push(cur->left);

    if(cur->right)
        q.push(cur->right);
    
  }
  
}


node* BSTUsingInorderRecursive(int inorder[],int start, int end){

  // creat BST recursively
  if(start > end) // if start goes more than end, then return null(means can't create BST)
      return NULL;

  int mid = (start + end)/2;

  // create root node
  node* root = new node(inorder[mid]);

  // create left subtree
  root->left = BSTUsingInorderRecursive(inorder,start,mid-1);

  // create right subtree
  root->right = BSTUsingInorderRecursive(inorder,mid+1,end);

  return root;
}


int main(){
  // input - 1 2 3 5 7 9 11
  // given a sorted array and we need to create BST(Binary search tree)
  int inorder[]={1,2,3,5,7,9,11};
  
  int start = 0, end =6; 
  node* root = BSTUsingInorderRecursive(inorder,start,end);
  
  levelOrderTraversal(root);

  
  return 0;
}