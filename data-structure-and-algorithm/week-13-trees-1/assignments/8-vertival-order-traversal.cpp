// leetcode hard - https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

// brute force 
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

    void traverse(TreeNode* root, map<int,map<int,vector<int> > >& datas, int row, int col){
        if(root==NULL)
            return;

        datas[col][row].push_back(root->val);

        traverse(root->left,datas,row+1,col-1);
        traverse(root->right,datas,row+1,col+1);
    }


    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,map<int,vector<int> > > datas;

        traverse(root,datas,0,0);

        vector<vector<int> > ans;
        for(auto col : datas){
            vector<int> temp;
            for(auto row :col.second){
                vector<int> temp1;
                for(auto dta : row.second)
                    temp1.push_back(dta);
                
                sort(temp1.begin(),temp1.end());
                
                for(auto x:temp1)
                    temp.push_back(x);
            }
            
            ans.push_back(temp);
            
        }

        return ans; 
    }
};

//------------------------------------------------------------------
//logic 2 -> using map and multiset
 
void traverse(TreeNode* root, map<int,map<int,multiset<int> > >& datas, int row, int col){
        if(root==NULL)
            return;

        datas[col][row].insert(root->val);

        traverse(root->left,datas,row+1,col-1);
        traverse(root->right,datas,row+1,col+1);
    }


    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
         map<int,map<int,multiset<int> > > datas;

        traverse(root,datas,0,0);

        vector<vector<int> > ans;
        for(auto col : datas){
            vector<int> temp;
            for(auto row :col.second){
                
                for(auto m:row.second)
                    temp.push_back(m);
               
            }
            
            ans.push_back(temp);
            
        }

        return ans; 
    }


//---------------------------------
// logic 3 - traverse by level order and above same data structure used to identify the row and col data.