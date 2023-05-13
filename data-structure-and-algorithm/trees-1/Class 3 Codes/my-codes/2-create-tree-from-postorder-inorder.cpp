// leet code - https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

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


node* build_tree_from_postorder_inorder(int postorder[],int inorder[],int size,int& postindex, int inorderStart,int inorderEnd){

    // base cases 
    if(inorderStart > inorderEnd || postindex < 0 ) // if start is more than end or postindex goes beyond 0
        return NULL;

    // 1. get the root of the tree from postorder -> postindex will be the index of root
    int element = postorder[postindex];
    postindex--; // decrement it

    // create node
    node* cur_node = new node(element);

    // 3. get index of root node from inorder array.
    int pos = findPosition(inorder,element,inorderStart,inorderEnd);


    // 4. create right subtree by recursion
    cur_node->right = build_tree_from_postorder_inorder(postorder,inorder,size,postindex, pos+1,inorderEnd);

    // 5. create left subtree by recursion
    cur_node->left = build_tree_from_postorder_inorder(postorder,inorder,size,postindex,inorderStart,pos-1);


    return cur_node;
}

void level_order_traversal(node* cur_node){
    // traverse tree by level by level
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
  int postindex = size-1;
  int inorderStart=0,inorderEnd = size-1;
  
  int postorder[]={9,15,7,20,3};
  int inorder[]={9,3,15,20,7};

  node* root = build_tree_from_postorder_inorder(postorder,inorder,size,postindex,inorderStart,inorderEnd);

  level_order_traversal(root);
  
  return 0;
};
