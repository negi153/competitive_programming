// leetcode easy - https://leetcode.com/problems/diameter-of-binary-tree/description/


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

    // solution 1 - go to every node and max diameter from left, right and current --> o(n^2)
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

//-------------------------------------------------------------------------------------------
// this method will find the max height of each node, and at every node it will find the current diameter and store into max if current diameter is more than existing diameter -> o(n)

    int diameter = 0;

    int height2(TreeNode* root){
        if(root==NULL)  
            return 0;

        // calculate max height of node
        int leftHeight = height2(root->left);
        int rightHeight = height2(root->right);
        
        // get current diameter
        int currentDiameter = leftHeight + rightHeight;

        if(currentDiameter > diameter)
            diameter = currentDiameter;

        return max(leftHeight, rightHeight)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height2(root);
        return diameter;
        
    }
