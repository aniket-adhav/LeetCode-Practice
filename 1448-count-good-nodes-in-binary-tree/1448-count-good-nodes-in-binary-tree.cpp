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
 int goodNodes(TreeNode* root,int maxVal=INT_MIN) {
        if(!root)return 0;
        
        maxVal=max(maxVal,root->val);
       int l= goodNodes(root->left,maxVal);
       int r=  goodNodes(root->right,maxVal);
        if(root->val>=maxVal) return l+r+1;
        return l+r;
    }
   
};