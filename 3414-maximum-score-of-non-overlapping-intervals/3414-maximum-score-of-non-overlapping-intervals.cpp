class Solution {
public:
    vector<array<int, 4>> arr;
    vector<int> nextIdx;
    map<pair<int, int>, pair<long long, vector<int>>> dp;

    pair<long long, vector<int>> solve(int i, int k) {
        if (i == arr.size() || k == 0) 
            return {0, {}};
        

        if (dp.count({i, k})) 
            return dp[{i, k}];
        

        auto skip = solve(i + 1, k);

        auto take = solve(nextIdx[i], k - 1);
        take.first += arr[i][2];
        take.second.push_back(arr[i][3]);
        sort(take.second.begin(), take.second.end());

        if (take.first > skip.first) 
            return dp[{i, k}] = take;
        

        if (take.first < skip.first) 
            return dp[{i, k}] = skip;
        

        return dp[{i, k}] = min(take.second, skip.second) == take.second ? take : skip;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        for (int i = 0; i < n; i++) {
            arr.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(arr.begin(), arr.end());

        vector<int> starts;
        for (auto &x : arr) 
            starts.push_back(x[0]);
        

        nextIdx.resize(n);
        for (int i = 0; i < n; i++) {
            nextIdx[i] = upper_bound(starts.begin(), starts.end(), arr[i][1]) - starts.begin();
        }

        return solve(0, 4).second;
    }
};