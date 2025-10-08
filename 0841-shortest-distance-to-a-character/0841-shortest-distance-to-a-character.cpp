class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans(n, n); // initialize with large value
        int prev = -n;

        // Left to right
        for (int i = 0; i < n; i++) {
            if (s[i] == c) prev = i;
            ans[i] = i - prev;
        }

        // Right to left
        prev = 2 * n;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) prev = i;
            ans[i] = min(ans[i], prev - i);
        }

        return ans;
    }
};
