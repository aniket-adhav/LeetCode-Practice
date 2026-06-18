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
        vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr) {

            // No left child, visit current node
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else {
                // Find inorder predecessor
                TreeNode* prev = curr->left;

                while (prev->right && prev->right != curr)
                    prev = prev->right;

                // Create thread
                if (prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                }
                // Thread already exists
                else {
                    prev->right = NULL;      // Remove thread
                    ans.push_back(curr->val); // Visit node
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};