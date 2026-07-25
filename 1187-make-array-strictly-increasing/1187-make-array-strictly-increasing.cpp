class Solution {
public:
    const int INF = 1e9;

    int solveTD(vector<int>& arr1, vector<int>& arr2, int prev, int i,
                map<pair<int, int>, int>& dp) {

        if (i == arr1.size())
            return 0;

        if (dp.find({prev, i}) != dp.end())
            return dp[{prev, i}];

        int op1 = INF;

        // Keep current element
        if (arr1[i] > prev) {
            op1 = solveTD(arr1, arr2, arr1[i], i + 1, dp);
        }

        // Replace current element
        int op2 = INF;
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);

        if (it != arr2.end()) {
            op2 = 1 + solveTD(arr1, arr2, *it, i + 1, dp);
        }

        return dp[{prev, i}] = min(op1, op2);
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {

        sort(arr2.begin(), arr2.end());

        // Remove duplicates from arr2
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

        map<pair<int, int>, int> dp;

        int ans = solveTD(arr1, arr2, -1, 0, dp);

        return ans == INF ? -1 : ans;
    }
};