class Solution {
private:
    bool check_substring(string s, string t) {
        if (s.length() > t.length()) return false;
        return t.contains(s);
    }

public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for (string s : patterns) {
            ans += check_substring(s, word) ? 1 : 0;
        }
        return ans;
    }
};