//leetcode easy - https://leetcode.com/problems/symmetric-tree/

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
    bool isMirror(TreeNode* p, TreeNode* q) {
        if(!p && !q) // if  p and q are null
            return true;
        
        if(p && q){ 
            return (p->val == q->val)
                && isMirror(p->left,q->right)
                && isMirror(p->right,q->left);
        }

        return false;
    }

    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left,root->right);
    }
};