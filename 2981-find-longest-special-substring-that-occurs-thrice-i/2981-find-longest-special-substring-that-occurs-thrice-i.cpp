class Solution {
public:
    bool possible(int mx, string& s) {
        int count = 0;


        char ch = s[0];

        vector<int> freq(26, 0);
        for (auto& x : s) {
            
            if (x != ch) {
                if (count >= mx)
                    freq[ch - 'a'] += count - mx + 1;
                if (freq[ch - 'a'] >= 3)
                    return true;
                count = 1;
                ch = x;
            } else
                count++;
        }
        return false;



    }
    int maximumLength(string s) {
        int l = 1, h = s.size(), res = -1;
        s += ' ';
        while (l <= h) {
            int guess = (l + h) / 2;
            if (possible(guess, s)) {
                res = guess;
                l = guess + 1;
            } else
                h = guess - 1;
        }
        return res;
    }
};