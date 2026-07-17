class Solution {
public:

    int solveMem(int n, vector<int>&dp){
        if(n==0 || n==1){
            return 1;
        }

        if(dp[n]!=-1) return dp[n];

        dp[n] = solveMem(n-1, dp)+solveMem(n-2, dp);
        return dp[n];
    }

    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        int ans = solveMem(n, dp);
        return ans;
    }
};