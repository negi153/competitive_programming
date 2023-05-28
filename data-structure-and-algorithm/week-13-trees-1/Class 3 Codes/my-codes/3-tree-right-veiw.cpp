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

node* build_tree(int a[],int n,int& i){

  if(a[i]==-1 || i>=n){
    i++;
    return NULL;
  }
      

  node* cur = new node(a[i]);
  cout<<"adding node - "<<a[i]<<endl;
  i++;
  cur->left=build_tree(a,n,i);
  cur->right=build_tree(a,n,i);

  return cur;
}


vector<int> rightSideView(node* root) {
        queue<node*> q;
        q.push(root);
        q.push(NULL);

        int lvl_right_node_found=1;
        vector<int> ans;

        while(!q.empty()){

            node* cur = q.front();
            q.pop();

            if(cur == NULL){
                
                lvl_right_node_found = 1;
                if(!q.empty()){
                    q.push(NULL);
                }

                continue;
            }

            if(lvl_right_node_found == 1){
                ans.push_back(cur->data);
                lvl_right_node_found=0;
            }

            if(cur->right)
                q.push(cur->right);
            
            if(cur->left)
                q.push(cur->left);

        }

        return ans;
    }

int main(void) {

  int a[]={1,2,-1,5,-1,-1,3,-1,4,9,-1,-1,-1};
  int n=13;
  int i=0;
  node* root = build_tree(a,n,i);

  // level_order_traversal(root);
  vector<int> ans = rightSideView(root);

  for(auto x: ans) cout<<x<<" ";
  
  return 0;
};
