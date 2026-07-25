class Solution {
public:
    int solveOptimal(vector<int>& arr, vector<int>& lis) {
        if (arr.size() == 0) return 0;

        vector<int> ans;

        lis.push_back(1);
        ans.push_back(arr[0]);

        for (int i = 1; i < arr.size(); i++) {

            if (arr[i] > ans.back()) {
                ans.push_back(arr[i]);
                lis.push_back(ans.size());
            }
            else {
                int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[index] = arr[i];
                lis.push_back(index + 1);
            }
        }

        return ans.size();
    }


    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> lis, lds;

        // LIS from left
        solveOptimal(nums, lis);

        // Reverse and compute LIS again (acts as LDS)
        reverse(nums.begin(), nums.end());
        solveOptimal(nums, lds);

        int n = nums.size();
        int largestMountain = 0;

        for (int i = 0; i < n; i++) {
            // Invalid peak
            if (lis[i] == 1 || lds[n - i - 1] == 1)
                continue;

            largestMountain = max(largestMountain,
                                lis[i] + lds[n - i - 1] - 1);
        }

        return n - largestMountain;
    }
};