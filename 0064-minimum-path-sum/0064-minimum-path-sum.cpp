class Solution {
public:
    int helper(vector<vector<int>>& grid, int m, int n, int i, int j, vector<vector<int>>&dp){
        if(i==m-1 && j==n-1){
            return grid[i][j];
        }

        if(j>=n || i>=m) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int right = INT_MAX;
        int down = INT_MAX;
        if(j<n-1) right = grid[i][j] + helper(grid, m, n, i, j+1, dp); 
        if(i<m-1) down = grid[i][j] + helper(grid, m, n, i+1, j, dp);
        dp[i][j] = min(right, down);

        return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));

        return helper(grid, m, n, 0, 0, dp);
    }
};