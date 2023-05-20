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

node* insertIntoBST(node* root,int data){

  // base case - if root is null, then create node
  if(root == NULL){
    node* cur_node = new node(data);
    return cur_node;
  }

  // if data is more than current ndoe, then add this node to right subtree, else add to left subtree

  if(data > root->data)
      root->right = insertIntoBST(root->right,data); // add to right subtree
  else
      root->left = insertIntoBST(root->left,data); // add to left subtree

  return root;
}


node* createBST(){
  // this function will take take input untill it finds -1, to create BST (Binary search tree)
  // and insert data into BST

  cout<<"Enter elements for BST - ";
  
  int temp;
  node* root = NULL;
  
  while(1){
    cin>>temp;

    // don't take further input if received -1
    if(temp == -1) 
      break;

    root = insertIntoBST(root,temp);
  }

    return root;
}


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

void inorderTraversal(node* cur_node){
  if (cur_node == NULL)
      return;

  inorderTraversal(cur_node->left);

  cout<<cur_node->data<<" ";

  inorderTraversal(cur_node->right);
  
}


void preorderTraversal(node* cur_node){
  if (cur_node == NULL)
      return;

  cout<<cur_node->data<<" ";
  
  preorderTraversal(cur_node->left);
  
  preorderTraversal(cur_node->right);
  
}

void postorderTraversal(node* cur_node){
  if (cur_node == NULL)
      return;

  postorderTraversal(cur_node->left);

  postorderTraversal(cur_node->right);

  cout<<cur_node->data<<" ";
  
}

bool searchElementInBST(node* root,int target){
    // base case - if root is null , then target element can't be there so return false
    if(root == NULL)
        return false;

    // if current node is the target element, then return true;
    if(root->data == target)
        return true;

    // if target is more than currrent node, then it might be present in right subtree else it might be present in left subtree

  if(target > root->data)
      return searchElementInBST(root->right,target);
  else
      return searchElementInBST(root->left,target);

  return false; // at the end if element is not found then return false
    
}

void inorder(node* root,vector<int>& inorder_bst){

  if(root == NULL)
      return;

  // 1. traverse left subtree
  inorder(root->left,inorder_bst);

  // 2. add element to vector
  inorder_bst.push_back(root->data);

  // 3. traverse right subtree
  inorder(root->right,inorder_bst);
  
}

void findMinMaxInBSTRecursive(node* root){

  // logic -> store the inorder of BST in a vector which will be the in a sorted order
  // first element will be smallest and last will be largest

  vector<int> inorder_bst;
  inorder(root,inorder_bst);

  cout<<"[recursion & vector] Max element in BST - "<<inorder_bst[inorder_bst.size()-1]<<endl;
  cout<<"[recursion & vector] Min element in BST - "<<inorder_bst[0]<<endl;
  
}

int findMaxBSTRecursive(node* root){
  // logic --> max element will be present int the right subtree only. so traverse right subtree untill right subtree of current node is null. in that case that node will be max

  if(root == NULL)
      return -1 ; // means there are no elements in BST
  
  if(root->right == NULL) // it right subtree of current node is null, then it is the max element
      return root->data;

  return findMaxBSTRecursive(root->right); // find max in right subtree
  
}

int findMinBSTRecursive(node* root){
   // logic -> min element will be present in the left subtree only. so traverse left subtree untill left subtree of current node is null. in that case that node will be min

    if(root == NULL) // if there are no elements then there is no min element
        return -1; 

    if(root->left == NULL) // if left subtree of current node is null, then it is min element
        return root->data;

    return findMinBSTRecursive(root->left); // find min in left subtree
}


void findMinMaxInBSTIterative(node* root){

  if(root == NULL)
      cout<<"There are no min and max element as BST is null"<<endl;

  // find max in BST
  node* temp = root;
  while(temp->right != NULL){ // iterate till right subtree of current node is null
    temp = temp->right; // go to right subtree
  }
  cout<<"[iterative] max element of BST - "<<temp->data<<endl;

  // find min in BST
  temp = root;
  while(temp->left != NULL){ // iterate till left subtree of current node is null
    temp = temp->left; // go to left subtree
  }
  cout<<"[iterative] min element of BST - "<<temp->data<<endl;
  
}


node* deleteNodeInBST(node* root, int target){

  if(root == NULL) // since there are no elements in tree to delete, then return NULL
      return NULL; 

  if(root->data == target){ // found the element now need to delete it

        if(root->left == NULL && root->right == NULL){
            // case 1 - when left and right subtree of target is null, then return NULL so BST will not have this node
          return NULL;
        }
        else if(root->left != NULL && root->right == NULL){
            //case 2 - when left of target is not null and right of target is null, then return left subtree to connect to the parent of root
            return root->left; 
        }
        else if(root->left == NULL && root->right != NULL){
            // case 3 - when left subtree of target is null and right subtree is not null, then return right subtree to connect to parent of root

          return root->right;
        }
        else{
          // case 4 - when left and right subtree of target is not null
          //   option 1 -> replace target node with maximum of the left subtree of target
          //   option 2 -> replace target node with minimum of the right subtree of target

          int max_from_left_subtree = findMaxBSTRecursive(root->left);

          root->data = max_from_left_subtree; // replace target node with maximum from left subtree of target

          // delete the node which replaced the target
          root->left = deleteNodeInBST(root->left,max_from_left_subtree);
          return root;
        }
    
  }
  else if(target > root->data){ // if target is more than the current then go to right subtree
      root->right =  deleteNodeInBST(root->right,target);
  }
  else{ // if target is less than current then go to left subtree

      root->left = deleteNodeInBST(root->left,target);
  }

  return root;
}


void inorderPredecessorSuccessorVectorRecursive(node* root, int target){
    // this function will find inorder predessor and successor of target node

    //logic -> store inorder of BST in vector and then iterate to find the inorder predessor and successor of the target node

    vector<int> inorder_bst;
    inorder(root,inorder_bst);

    for(int i=0;i<inorder_bst.size();i++){
        if(inorder_bst[i] == target){ //if target found in BST
            if(i-1 >= 0)
              cout<<"[vector & recursion] inorder Predecessor of "<<target<<" is "<<inorder_bst[i-1]<<endl;
            else
              cout<<"[vector & recursion] Inorder predecessor does not exist for target - "<<target<<endl;

            if(i+1 < inorder_bst.size())
                cout<<"[vector & recursion] Inorder successor of target "<<target<<" is "<<inorder_bst[i+1]<<endl;
            else
                cout<<"[vector & recursion] Inorder successor does not exist for target - "<<target<<endl;

          return;
        }
    }
  
    cout<<"Target element is not present in BST";
  
}


void inorderPredecessorRecursive(node* root,int target,int& inorder_predecessor, int& found){
  if(root == NULL)
      return;

  inorderPredecessorRecursive(root->left,target,inorder_predecessor,found);

  if(found)
      return;
  
  if(root->data == target){
    found = 1;
    return;
  }

  inorder_predecessor = root->data;

  if(found == 0)
    inorderPredecessorRecursive(root->right,target,inorder_predecessor,found);
  
}


int main(){
  // input - 5 8 0 1 9 6 11 10 -1
  node* root = createBST(); // create a BST(binary search tree)

  cout<<"level order traversal - "<<endl;
  levelOrderTraversal(root);

  cout<<endl<<"inorder traversal (Sorted in case of BST)- ";
  inorderTraversal(root);

  cout<<endl<<"preorder traversal - ";
  preorderTraversal(root);

  cout<<endl<<"postorder traversal - ";
  postorderTraversal(root);
  cout<<endl;
  
  int target = 4;
  if(searchElementInBST(root,target))
    cout<<"Element "<<target<<" found in BST"<<endl;
  else
    cout<<"Element "<<target<<" not found in BST"<<endl;

  findMinMaxInBSTRecursive(root); // find mix max using vector and inorder

  cout<<"[recursion] Max element of BST - "<<findMaxBSTRecursive(root)<<endl; // find max without vector and using recursion stack memory

  cout<<"[recursion] Min element of BST - "<<findMinBSTRecursive(root)<<endl; // find min without vector and using recursion stack memory

  findMinMaxInBSTIterative(root); // find min and max of BST without recursion and without vector. 
  
  target = 5; // node to delete from BST
  root = deleteNodeInBST(root,target); // delete node from BST

  cout<<"level order traversal after deleting node "<<target<<" - "<<endl;
  levelOrderTraversal(root);

  cout<<endl<<"inorder traversal (Sorted in case of BST) after deleting node "<<target<<" - ";
  inorderTraversal(root);
  cout<<endl;
  
  target = 0;
  inorderPredecessorSuccessorVectorRecursive(root,target);

  int inorder_predecessor=-1,found=0;
  inorderPredecessorRecursive(root,target,inorder_predecessor,found);

  if(inorder_predecessor != -1)
    cout<<"[recursive] inorder predessor of "<<target<<" - "<<inorder_predecessor<<endl;
  else
    cout<<"[recursive] inorder predessor not found for target "<<target<<endl;
  
  return 0;
}