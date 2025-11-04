class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> m;

        for (int i = 0; i + k <= n; i++) {
            m.clear();
            // build frequency for current window
            for (int j = i; j < i + k; j++) {
                m[nums[j]]++;
            }

            priority_queue<pair<int, int>> pq;
            for (auto &c : m) {
                pq.push({c.second, c.first});
            }

            int t = x;
            int sum = 0;
            while (t > 0 && !pq.empty()) {
                sum += pq.top().second * pq.top().first;
                pq.pop();
                t--;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
