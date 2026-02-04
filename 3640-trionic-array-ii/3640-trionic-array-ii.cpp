class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {

        int n = nums.size();
        long long res = -1e16;

        for (int i = 1; i < n - 2; i++) {

            int a = i, b = i;
            long long net = nums[a];

            while (b + 1 < n && nums[b + 1] < nums[b]) {
                net += nums[b + 1];
                b++;
            }

            if (a == b) continue;

            int c = b;

            long long left = 0, right = 0;
            long long lx = LLONG_MIN, rx = LLONG_MIN;

            while (a - 1 >= 0 && nums[a - 1] < nums[a]) {
                left += nums[a - 1];
                lx = max(lx, left);
                a--;
            }

            if (a == i) continue;

            while (b + 1 < n && nums[b + 1] > nums[b]) {
                right += nums[b + 1];
                rx = max(rx, right);
                b++;
            }

            if (b == c) continue;

            i = b - 1;
            res = max(res, lx + net + rx);
        }

        return res;
    }
};