bool solve(TreeNode* root, long long int lower_bound,long long int upper_bound){
        if(root == NULL)
            return true;
        
        if(root->val > lower_bound && root->val < upper_bound){
                bool leftAns = solve(root->left,lower_bound, root->val);
                bool rightAns = solve(root->right,root->val, upper_bound);

                return leftAns && rightAns;
        }
        else
            return false;
    }
    bool isValidBST(TreeNode* root) {
        long long int lower_bound = -4294967296;
        long long int upper_bound = 4294967296;
        bool ans = solve(root, lower_bound,upper_bound);

        return ans;
    }

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;

        // if p < root and q < root -> then ans exist in left subtree
        // if p > root and q > root -> then ans exist in right subtree
        // // if  
        //     case 1 - p< root and q> root
        //     case 2 - p > root and q < root
        //     if any of the case exist then current node is LCA 
        
        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }