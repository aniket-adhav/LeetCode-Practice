class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        dfs(root, root->val, root->val);
        return ans;
    }

private:
    int ans = 0;

    void dfs(TreeNode* node, int minVal, int maxVal) {
        if (!node) return;

        ans = max(ans, max(abs(node->val - minVal), abs(node->val - maxVal)));

        minVal = min(minVal, node->val);
        maxVal = max(maxVal, node->val);

        dfs(node->left, minVal, maxVal);
        dfs(node->right, minVal, maxVal);
    }
};