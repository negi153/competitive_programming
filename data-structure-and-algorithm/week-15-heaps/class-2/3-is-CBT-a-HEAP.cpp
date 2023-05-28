#include <iostream>
#include<queue>

using namespace std;

pair<bool,int> solve(Node* root){

  if(root=NULL){
      pair<bool,int> p = make_pair(true,INT_MIN);
    return p;
  }

  if(root->left == NULL && root->right == NULL){
    pair<bool,int> p = make_pair(true,root->data);
    return p;
  }

  pair<bool,int> left = solve(root->left);
  pair<bool,int> right = solve(root->right);
  
  if(left.first == true &&
    right.first == true &&
    root->data > left.second &&
    root->data > right.second)

    return make_pair(true, root->value);
  else
    return make_pair(false, root->value);


}

int main() {
  

  return 0;
}