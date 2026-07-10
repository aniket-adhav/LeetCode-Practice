class Solution {
public:
    int nCr(int n, int r) {
        
        if (r > n)
            return 0;
        if (r == 0 || r == n)
            return 1;
        int res = 1;


        r = min(r, n - r);
        for (int i = 0; i < r; i++) {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }

    int countVowelStrings(int n) { return nCr(n + 4, n); }
};