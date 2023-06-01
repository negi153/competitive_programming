// leetcode medium - https://leetcode.com/problems/path-sum-iii/

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
    int totalPaths = 0;

    void no_of_paths_from_root(TreeNode* root, long long targetSum){
        if(root==NULL)
            return;
        
        if(root->val == targetSum){
            totalPaths++;
        }

        no_of_paths_from_root(root->left,targetSum-root->val);
        no_of_paths_from_root(root->right,targetSum-root->val);

    }

   int pathSum(TreeNode* root, long long targetSum) { // o(n^2) --> from each node find the no. of paths from that node to leaf
        
        if(root){
            no_of_paths_from_root(root,targetSum);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);
        }

        return totalPaths;
    }
};