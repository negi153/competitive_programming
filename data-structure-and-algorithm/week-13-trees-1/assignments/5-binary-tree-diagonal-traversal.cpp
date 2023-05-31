// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

//  base logic -> when going to left then increment coutner to 1 and if going to right then do nothing


// logic 1 - store nodes in map for each diagonal
void traverse(Node* root, int d, map<int,vector<int> >& mp){
    if(root==NULL)
        return;
    
    mp[d].push_back(root->data);
    
    traverse(root->left,d+1,mp);
    traverse(root->right,d,mp);
}

vector<int> diagonal(Node *root)
{
   map<int,vector<int> > mp; // store values in ordered map for each diagonal
   traverse(root,0,mp);
   
   vector<int> ans ;
   for(auto x : mp){
       for(auto y : x.second)
            ans.push_back(y);
   }
   
   return ans;
}


//-------------------------------------------------------------------------------
// easy way
// logic - pick elemnt from queue, go to the right side of that node untill null found -> we are doning this to find the first digonal
// if we encounter any left node, then push it to queue (we will sese that later)


vector<int> diagonal(Node *root){
    vector<int> ans;
    
    if(root == NULL) return ans;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        
        Node* temp =q.front();
        q.pop();
        while(temp != NULL){
            ans.push_back(temp->data);
            
            if(temp->left){
                q.push(temp->left);
            }
            
            temp=temp->right;
        }
        
    }
    
    return ans;
    
}