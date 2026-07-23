class Solution {
public:
    
    int helper(string&s, string&t, int i, int j, vector<vector<int>>&dp){

        if(j==t.size()){
            return 1;
        }

        if(i==s.size()){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int count = 0;

        if(s[i]==t[j]){
            count += helper(s, t, i+1, j+1, dp);
        }

        count += helper(s, t, i+1, j, dp);

        dp[i][j] = count;

        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size()+1, vector<int>(t.size()+1, -1));
        return helper(s, t, 0, 0, dp);
    }
};