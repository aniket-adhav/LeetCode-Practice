class Solution {
public:
    int minCost(int n) {
        int dp[501];
        for (int i = 0; i <= n; i++)
            dp[i] = 1e9;

        dp[1] = 0;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                dp[i] = min(dp[i], j * (i - j) + dp[j] + dp[i - j]);
            }
        }

        return dp[n];
    }
};