class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1000000007;
        const int MAXV = 100001;

        static int memo[MAXV], duplets[MAXV];
        memset(memo, 0, sizeof memo);
        memset(duplets, 0, sizeof duplets);

        int res = 0;
        for(int number : nums) {
            res = (res + duplets[number]) % MOD;
            int twon = number * 2;
            if (twon < MAXV) {
                duplets[twon] = (duplets[twon] + memo[twon]) % MOD;
            }
            memo[number]++;
        }

        return res;
    }
};