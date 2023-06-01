//leetcode easy - https://leetcode.com/problems/balanced-binary-tree/description/

// check if tree is balanced or not


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int height(TreeNode* root){
        if(root == NULL)
            return 0;
        
        int left = height(root->left);
        int right = height(root->right);

        return max(left,right) + 1;
    }

    bool isBalanced(TreeNode* root) { // time complexity - o(n^2)
        if(root == NULL)
            return true;

        bool isLeftBalanced = isBalanced(root->left);
        bool isRightBalanced = isBalanced(root->right);

        // check if current node is balance or not
        int lh = height(root->left);
        int rh = height(root->right);

        bool isCurrentBalanced = false;
        if(abs(lh-rh) <= 1)
             isCurrentBalanced = true;
        

        if(isLeftBalanced && isRightBalanced && isCurrentBalanced)
            return true;
        
        return false;
    }


};





// ----------------------------------------------------------------------------------
// here we will go to each node and find the max height from left subtree and right subtree ->  check if current node is balanced or note,
// if not then mark flag as false --> o(n)
    bool isBalancedFlag = true;

    int height2(TreeNode* root){
        if(root == NULL)
            return 0;
        
        int left = height2(root->left);
        int right = height2(root->right);
        int currHeight = max(left,right) + 1; 
        
        if(abs(left-right) > 1)
            isBalancedFlag = false;

        // cout<<"node - "<<root->val<<", flag - "<<isBalancedFlag<<endl;
        return currHeight;
    }

    bool isBalanced(TreeNode* root)
    {
        height2(root);
        return isBalancedFlag;
    }