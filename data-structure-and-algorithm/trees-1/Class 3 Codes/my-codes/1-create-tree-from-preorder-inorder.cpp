// leet code (medium) - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

#include <iostream>
#include<queue>

using namespace std;

class node{
    public:
    
    int data;
    node* left=NULL;
    node* right=NULL;

    node(int data){
        this->data=data;
    }
};


int findPosition(int inorder[],int element,int inorderStart,int inorderEnd){
    // find the element between range [inorderStart, inorderEnd]
    for(int i=inorderStart;i<=inorderEnd;i++)
        if(inorder[i] == element)
            return i;
    
    return -1; // if element not present return -1 (this will never happen)
}


node* build_tree_from_preorder_inorder(int preorder[],int inorder[],int size,int& preindex, int inorderStart,int inorderEnd){

    // base cases 
    if(inorderStart > inorderEnd || preindex >= size) // if start is more than end
        return NULL;

    // 1. get the root of the tree from preorder -> preindex will be the index of root
    int element = preorder[preindex];
    preindex++; // increment it

    // create node
    node* cur_node = new node(element);

    // 3. get index of root node from inorder array.
    int pos = findPosition(inorder,element,inorderStart,inorderEnd);

    // 4. create left subtree by recursion
    cur_node->left = build_tree_from_preorder_inorder(preorder,inorder,size,preindex,inorderStart,pos-1);

    // 5. create right subtree by recursion
    cur_node->right = build_tree_from_preorder_inorder(preorder,inorder,size,preindex, pos+1,inorderEnd);

    return cur_node;
}

void level_order_traversal(node* cur_node){

    cout<<"level order traversal - "<<endl;

    queue<node*> q;
    
    q.push(cur_node);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
          cout<<endl; // level completed here

          if(!q.empty()) // if elements are present in queue, then only insert null
            q.push(NULL); // at this time all the nodes visited from previous level
          continue;
        }
        cout<<temp->data <<" ";

        if(temp->left)
            q.push(temp->left);
        
        if(temp->right)
            q.push(temp->right);

    }

}

int main(void) {

  int size = 5;
  int preindex = 0;
  int inorderStart=0,inorderEnd = size-1;
  
  int preorder[]={3,9,20,15,7};
  int inorder[]={9,3,15,20,7};

  node* root = build_tree_from_preorder_inorder(preorder,inorder,size,preindex,inorderStart,inorderEnd);

  level_order_traversal(root);
  
  return 0;
};
