// leetcode - easy - https://leetcode.com/problems/same-tree/


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
    

    bool isSameTree(TreeNode* p, TreeNode* q) { // time -> worst case -> visit all nodes - o(n)
        if(!p && !q) // if  p and q are null
            return true;
        
        if(p && q){ // if p and q are not nulll, then their value should be same and their left subtree and right subtree should also be same
            return (p->val == q->val)
                && isSameTree(p->left,q->left)
                && isSameTree(p->right,q->right);
        }

        return false;
    }
};