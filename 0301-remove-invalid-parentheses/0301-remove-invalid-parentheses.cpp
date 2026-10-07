class Solution {
public:
    unordered_set<string> uq_vps;

    int checkVPS(const string& s) {
        int open = 0, close = 0, remCnt = 0;
        for (char c : s) {
            if (c == ')') close++;
            if (c == '(') open++;

            if (close > open) {
                close = 0, open = 0;
                remCnt++;
            }
        }

        if (open - close != 0) remCnt += (open - close);
        return remCnt;
    }

    void f(int start, int removed, int minRemoval, const string& s, vector<bool>& rem) {
        if (removed == minRemoval) {
            string vps;
            for (int k = 0; k < (int)s.size(); k++) {
                if (!rem[k]) vps += s[k];
            }
            if (checkVPS(vps) == 0) uq_vps.insert(vps);
            return;
        }

        for (int j = start; j < s.size(); j++) {
            if (s[j] != '(' && s[j] != ')') continue;     
            if (j > start && s[j] == s[j - 1]) continue;   

            rem[j] = true;
            f(j + 1, removed + 1, minRemoval, s, rem);
            rem[j] = false;                            
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int minRemoval = checkVPS(s);
        if (minRemoval == 0) return {s};

        vector<bool> rem(s.size(), false);
        f(0, 0, minRemoval, s, rem);

        vector<string> res (uq_vps.begin(), uq_vps.end());
        return res;
    }
};