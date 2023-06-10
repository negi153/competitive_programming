// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

vector<int> leftView(Node *root)
{
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    int level = 0;
    
    if(root == NULL)
        return ans;
    
    while(!q.empty()){
        int n=q.size();
        
        while(n--){
            Node* cur = q.front();
            q.pop();
            
            if(level == ans.size()){
                ans.push_back(cur->data);
            }
            
            if(cur->left)
                q.push(cur->left);
            
            if(cur->right)
                q.push(cur->right);
            
        }
        
        level++;
    }
    
    
    return ans;
}
