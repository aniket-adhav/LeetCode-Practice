class Solution {
public:
    const long long MOD1 = 1e9 + 7;
    const long long MOD2 = 1e9 + 9;

    const long long P1 = 911382323;
    const long long P2 = 972663759;

    pair<long long, long long> get_hash(vector<int>& v, int l, int r) {
        long long h1 = 0;
        long long h2 = 0;

        for (int i = l; i <= r; i++) {
            h1 = (h1 * P1 + v[i]) % MOD1;
            h2 = (h2 * P2 + v[i]) % MOD2;
        }

        return {h1, h2};
    }

    map<pair<long long, long long>, int> mp;
    void solve(int len, vector<int>& a) {
        int n = a.size();
        long long pow1 = 1;
        long long pow2 = 1;

        for (int i = 0; i < len - 1; i++) {
            pow1 = (pow1 * P1) % MOD1;
            pow2 = (pow2 * P2) % MOD2;
        }

        long long h1 = 0;
        long long h2 = 0;

        
        for (int i = 0; i < len; i++) {
            h1 = (h1 * P1 + a[i]) % MOD1;
            h2 = (h2 * P2 + a[i]) % MOD2;
        }

        mp[{h1, h2}]++;

        for (int i = len; i < n; i++) {
            h1 = (((h1 - (a[i - len] * pow1) % MOD1 + MOD1) % MOD1) * P1 +
                  a[i]) %
                 MOD1;

            h2 = (((h2 - (a[i - len] * pow2) % MOD2 + MOD2) % MOD2) * P2 +
                  a[i]) %
                 MOD2;

            mp[{h1, h2}]++;
        }
    }
    bool check(int len, vector<int>& nums) {
        mp.clear();
        solve(len, nums);
        for (auto [val, freq] : mp) {
            if (freq == 1)
                return true;
        }

        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid, nums))
                r = mid - 1;
            else
                l = mid + 1;
        }

        return l;
    }
};