class Solution {
public:

    int helper(int m, int n, int i, int j, vector<vector<int>>&dp){
        if(i==m-1 && j==n-1){
            return 1;
        }

        if(j>=n || i>=m) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
       

        int right = 0;
        int down = 0;
        if(j<n-1) right += helper(m, n, i, j+1, dp); 
        if(i<m-1) down += helper(m, n, i+1, j, dp);
        dp[i][j] = right+down;
        return dp[i][j];
    }
    
    int uniquePaths(int m, int n) {

        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return helper(m, n, 0, 0, dp);

        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==0 || j==0) dp[i][j]=1;
        //         else dp[i][j]=dp[i-1][j] + dp[i][j-1];
        //     }
        // }
        // return dp[m-1][n-1];
    }
};