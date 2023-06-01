// gfg - https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1

int convert(Node* node){
        if(node == NULL)
            return 0;
        
        int leftSum = convert(node->left);
        
        int rightSum = convert(node->right);
        
        int cur_element = node->data;
        
        node->data = leftSum + rightSum;
        
        return cur_element + node->data;
    }
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        convert(node);
            
        
        
    }