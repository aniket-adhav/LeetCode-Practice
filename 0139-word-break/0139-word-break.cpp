class Solution {
public:
    bool check(vector<string>& wordDict, string s) {
        for (auto i : wordDict) {
            if (i == s)
                return true;
        }
        return false;
    }

    bool solve(string &s, vector<string>& wordDict, int start, vector<int>&dp) {
        if (start == s.size())
            return true;

        if(dp[start]!=-1) return dp[start];

        string word = "";
        bool flag = false;

        for (int i = start; i < s.size(); i++) {
            word += s[i];

            if (check(wordDict, word)) {
                flag = flag || solve(s, wordDict, i + 1, dp);
            }
        }
        dp[start]=flag;
        return dp[start];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size()+1, -1);
        return solve(s, wordDict, 0, dp);
    }
};