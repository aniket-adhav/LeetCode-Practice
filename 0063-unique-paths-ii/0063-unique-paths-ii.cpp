class Solution {
public:

    int helper(vector<vector<int>>& obstacleGrid, int m, int n, int i, int j, vector<vector<int>>&dp){
        if(i==m-1 && j==n-1 && obstacleGrid[i][j]!=1){
            return 1;
        }

        if(j>=n || i>=m) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
       

        int right = 0;
        int down = 0;

        if(obstacleGrid[i][j]!=1 && j<n-1) right += helper(obstacleGrid, m, n, i, j+1, dp); 
        if(obstacleGrid[i][j]!=1 && i<m-1) down += helper(obstacleGrid, m, n, i+1, j, dp);

        dp[i][j] = right+down;
        return dp[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return helper(obstacleGrid, m, n, 0, 0, dp);
    }
};



 

