class Solution {
public:
    int helper(string&s, string&t, int i, int j, vector<vector<int>>&dp){
        if(i>=s.size()){
            return 0;
        }

        if(j>=t.size()){
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;

        if(s[i]==t[j]){
            ans = 1 + helper(s, t, i+1, j+1, dp);
        }

        else{
            ans = 0 + max(helper(s, t, i+1, j, dp), helper(s, t, i, j+1, dp));
        }

        dp[i][j] = ans;
        return dp[i][j];
    }

    int longestPalindromeSubseq(string s) {
        string t = s;
        vector<vector<int>>dp(s.size()+1, vector<int>(s.size()+1, -1));
        reverse(t.begin(), t.end());

        return helper(s, t, 0, 0, dp);
    }
};