#include <iostream>
# include<queue>
using namespace std;

class node {
public:
  int data;
  node *left = NULL;
  node *right = NULL;

  node(int data) { this->data = data; }
};

node *build_tree() {
  int data;
  cout << "Enter data - ";
  cin >> data;

  // base condition
  if (data == -1) // means node is null
    return NULL;

  node *current_node = new node(data);

  cout << "Enter left child of node " << data << " :" << endl;
  current_node->left = build_tree(); // build left tree

  cout << "Enter right child of node " << data << " :" << endl;
  current_node->right = build_tree(); // build right tree

  return current_node;
}

void recursive_traverse_tree(node *current_node) {

  if (current_node == NULL)
    return;

  cout << "current node - " << current_node->data << endl;

  recursive_traverse_tree(current_node->left);
  recursive_traverse_tree(current_node->right);
}

void level_order_traversal(node* root) {

  // if root is null, then return
  if(root == NULL)
    return;

  queue<node*> q;
  q.push(root);

  while(!q.empty()){
    node* current_node = q.front();
    q.pop();

    cout<<current_node->data<<" ";

    if(current_node->left) // push if left part is not null
      q.push(current_node->left);

    if(current_node->right) // push if right part is not null
      q.push(current_node->right);
  }
  
  
}


void level_order_traversal_by_level(node* root){
  // this function will traverse tree level by level and is going to print data level by level

  if(root == NULL)
    return;

  queue<node*> q;
  q.push(root);
  q.push(NULL); // denotes ending of level after root

  while(!q.empty()){
    node* current_node = q.front();
    q.pop();

    if(current_node == NULL){ // if current node is null, means we visited all the nodes of a level
      cout<<endl; // line change if found null
      
      if(!q.empty()) // if queue is not empty, then push NULL
        q.push(NULL);

      continue;
    }
    cout<<current_node->data<<" ";

    if(current_node->left) // push if left part is not null
      q.push(current_node->left);

    if(current_node->right) // push if right part is not null
      q.push(current_node->right);
  }
  
}

void inorder_traversal(node* current_node){
  // inorder :  left_subtree -->  current node --> right subtree
  
  if(current_node == NULL) // return if current_node is null
    return;

  // traverse left subtree
  inorder_traversal(current_node -> left);

  cout<<current_node->data<<" ";

  // traverse right sub tree
  inorder_traversal(current_node -> right);

}

void preorder_traversal(node* current_node){
  // preorder : current node --> left_subtree --> right subtree
  
  if(current_node == NULL) // return if current_node is null
    return;

  cout<<current_node->data<<" ";
  
  // traverse left subtree
  preorder_traversal(current_node -> left);
  
  // traverse right sub tree
  preorder_traversal(current_node -> right);

}

void postorder_traversal(node* current_node){
  // inorder :  left_subtree -->  right subtree --> current node
  
  if(current_node == NULL) // return if current_node is null
    return;

  // traverse left subtree
  postorder_traversal(current_node -> left);

  // traverse right sub tree
  postorder_traversal(current_node -> right);

  cout<<current_node->data<<" ";
}

int height(node* current_node){

  // this funciton will return height of tree
  //height of tree -> maximum no. of nodes in longest path from root to leaf

  if(current_node == NULL) //if node is null, then height = 0
      return 0;

  int left_height = height(current_node->left);
  int right_height = height(current_node->right);

  int tree_height = max(left_height,right_height) + 1;

  return tree_height;
}

int main() {
  node *root = NULL;
  root = build_tree();

  cout<<"recursive tree traversal - "<<endl;
  recursive_traverse_tree(root);

  cout<<"level order traversal - ";
  level_order_traversal(root);
  cout<<endl;

  cout<<"level order traversal (level by level) -"<<endl;
  level_order_traversal_by_level(root);
  cout<<endl;

  cout<<"inorder traversal - ";
  inorder_traversal(root);
  cout<<endl;

  cout<<"preorder traversal - ";
  preorder_traversal(root);
  cout<<endl;

  cout<<"postorder traversal - ";
  postorder_traversal(root);
  cout<<endl;


  cout<<"height of tree - "<<height(root)<<endl;
}