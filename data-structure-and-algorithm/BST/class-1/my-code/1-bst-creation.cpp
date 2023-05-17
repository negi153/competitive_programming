#include <iostream>
#include<queue>

using namespace std;

class node{
  public:
   int data;
    node* left=NULL;
    node* right=NULL;

  node(int data){
    this->data= data;
  }
};

node* insertIntoBST(node* root,int data){
    if(root==NULL){
      node* cur_node = new node(data);
      return cur_node;
    }

    if(data < root->data){
      root->left = insertIntoBST(root->left,data);
    }
    else{
      root->right = insertIntoBST(root->right,data);
    }

  return root;
}

void take_input(node* &root){
  int tmp;
  cin>>tmp;

  while(tmp!=-1){
    root = insertIntoBST(root,tmp);
    cin>>tmp;
  }

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


int main() {
  node* root =NULL;

  cout<<"Enter data - ";
  take_input(root);


  level_order_traversal(root);
}