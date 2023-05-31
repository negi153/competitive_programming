// leetcode medium - https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// my solution using level order traversal --
// logic - > travers as level order, for flag ==0, show anser from left to right and for flag ==1, show answer right to left

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int> > ans;
        if(root==NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int flag = 0; // 0 means left to right, 1 means right to left
        vector<int> tt;

        while(!q.empty()){

            TreeNode* temp = q.front();
            q.pop();

            if(temp == NULL){
                
                if(flag == 0){
                    ans.push_back(tt);
                    flag=1;
                }
                    
                else{
                    flag=0;
                    reverse(tt.begin(),tt.end());
                    ans.push_back(tt);
                }
                    
                
                tt.clear();

                if(!q.empty()){
                    q.push(NULL);
                }

                continue;
            }

            tt.push_back(temp->val);
            // cout<<temp->val<<endl;

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);

        }

        return ans;
    }
};

// ---------------------------------------------------------------

// second method  --> when we are at the starting of each level, then q size will the number of element which is going to be present in that level

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans ;
        if(root == NULL) return ans;

        bool LtoRdir = true;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int width = q.size();
            vector<int> oneLevel(width);

            for(int i=0;i<width;i++){
                TreeNode* front = q.front();
                q.pop();

                int index = LtoRdir ? i:width-i-1; // find the index based on the flag
                oneLevel[index] = front->val;

                if(front->left)
                    q.push(front->left);
                
                if(front->right)
                    q.push(front->right);

            }

            LtoRdir = !LtoRdir; // change directions
            ans.push_back(oneLevel);


        }


        return ans;
    }