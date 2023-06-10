vector<int> topView(Node *root)
    {
        vector<int> ans;
        map<int,int> mp;
        
        queue<pair<Node*,int> > q;
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*, int> p = q.front();
            Node* cur_node = p.first;
            int dis = p.second;
            q.pop();
            
            if(mp.find(dis) == mp.end()){
                // not present
                mp[dis] = cur_node->data;
            }
            
            if(cur_node->left)
                q.push(make_pair(cur_node->left,dis-1));
            
            if(cur_node->right)
                q.push(make_pair(cur_node->right,dis+1));
            
        }
        
        for(auto x:mp)
            ans.push_back(x.second);
        
        return ans;    
    }