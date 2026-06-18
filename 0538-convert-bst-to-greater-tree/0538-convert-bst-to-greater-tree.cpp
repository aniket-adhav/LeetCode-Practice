
class Solution {
public:

    void inorderArray(TreeNode* root, vector<int>&inorder){
        if(root==nullptr){
            return;
        }

        inorderArray(root->left, inorder);
        inorder.push_back(root->val);
        inorderArray(root->right, inorder);
    }

    void SumArray(vector<int>&inorder){
        int n = inorder.size();
        for(int i=n-2; i>=0; i--){
            inorder[i]=inorder[i]+inorder[i+1];
        }
    }


    void inorderArrayfill(TreeNode* &root, vector<int>&inorder, int &i){
        if(root==nullptr){
            return;
        }

        inorderArrayfill(root->left, inorder, i);
        root->val = inorder[i++];
        inorderArrayfill(root->right, inorder,i);
    }

    TreeNode* convertBST(TreeNode* root) {
        vector<int>inorder;
        inorderArray(root, inorder);
        SumArray(inorder);


        int i =0;
        inorderArrayfill(root, inorder, i);
        
        return root;

    }
};