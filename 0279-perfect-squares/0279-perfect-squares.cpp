class Solution {
public:
    int noOfperfSqrt(int n, vector<int>&dp){
        //basecase
        if(n==0) return 1;
        if(n<0) return 0;

        if(dp[n]!=-1) return dp[n];

        int ans = INT_MAX;
        int i = 1;
        int end = sqrt(n);
        while(i<=end){
            int prefectSquare = i*i;
            int numofPerfSquare = 1 + noOfperfSqrt(n-prefectSquare, dp);
            if(numofPerfSquare<ans){
                ans=numofPerfSquare;
            }
            i++;
        }

        dp[n]=ans;
        return dp[n];
    }
    int numSquares(int n) {
        vector<int>dp(n+1, -1);
        return noOfperfSqrt(n, dp)-1;
    }
};