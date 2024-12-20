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

        int lh = height(root->left);
        int rh = height(root->right);
        int ans = max(lh,rh) + 1;

        // cout<<"node -" << root->val <<", height - "<<ans<<endl;
        return ans;
    }

    int diameterOfBinaryTree1(TreeNode* root) {
        if(root == NULL) 
            return 0;
        
        // height(root);
        // return 0;

        int leftAns = diameterOfBinaryTree(root->left);
        int rightAns = diameterOfBinaryTree(root->right);
        int currentDiameter = height(root->left) + height(root->right);
        int ans = max(max(leftAns,rightAns),currentDiameter);

        // cout<<"node - "<<root->val<<", left D - "<<leftAns<<", right D - "<<rightAns<<", current D - "<<currentDiameter<<", Diameter - "<<ans<<endl;
        return ans;
    }
};