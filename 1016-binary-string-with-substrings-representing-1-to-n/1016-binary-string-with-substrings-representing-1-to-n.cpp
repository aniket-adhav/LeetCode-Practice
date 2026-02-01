class Solution {
public:
    bool queryString(string s, int n) {
         unordered_set<int> seen;
        int len = s.size();

        for (int i = 0; i < len; ++i) {
            if (s[i] == '0') continue; 

            int num = 0;
            for (int j = i; j < len && j - i < 32; ++j) { 
                num = (num << 1) | (s[j] - '0');
                if (num > n) break;
                seen.insert(num);
            }
        }

        return seen.size() >= n;
    }
};