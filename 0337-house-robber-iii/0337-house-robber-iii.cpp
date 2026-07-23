class Solution {
public:
    int solve(TreeNode* root, unordered_map<TreeNode*, int>& dp) {
        if (!root)
            return 0;

        if (dp.find(root) != dp.end())
            return dp[root];

        int robThisHouse = 0, dontRobThisHouse = 0;

        // Rob current house
        robThisHouse += root->val;

        if (root->left)
            robThisHouse += solve(root->left->left, dp) +
                            solve(root->left->right, dp);

        if (root->right)
            robThisHouse += solve(root->right->left, dp) +
                            solve(root->right->right, dp);

        // Don't rob current house
        dontRobThisHouse += solve(root->left, dp) +
                            solve(root->right, dp);

        dp[root] = max(robThisHouse, dontRobThisHouse);
        return dp[root];
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return solve(root, dp);
    }
};