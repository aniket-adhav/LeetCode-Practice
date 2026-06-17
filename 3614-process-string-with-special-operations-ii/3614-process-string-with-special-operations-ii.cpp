class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        const long long LIM = 1e15;

        vector<long long> len(n + 1, 0);

       
        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (c >= 'a' && c <= 'z') {
                len[i + 1] = min(LIM, len[i] + 1);
            }
            else if (c == '*') {
                len[i + 1] = max(0LL, len[i] - 1);
            }
            else if (c == '#') {
                len[i + 1] = min(LIM, len[i] * 2);
            }
            else { 
                len[i + 1] = len[i];
            }
        }

        if (k >= len[n]) return '.';

        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];

            if (c >= 'a' && c <= 'z') {
                if (k == len[i])
                    return c;
            
            }
            else if (c == '*') {
        
            }
            else if (c == '#') {
                long long oldLen = len[i];
                if (k >= oldLen)
                    k -= oldLen;
            }
            else { 
                if (len[i] > 0)
                    k = len[i] - 1 - k;
            }
        }

        return '.';
    }
};