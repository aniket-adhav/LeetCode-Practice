class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());

        if (restrictions.back()[0] != n)
            restrictions.push_back({n, n - 1});

        int m = restrictions.size();

        for (int i = 1; i < m; i++) {
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i - 1][1] +
                (restrictions[i][0] - restrictions[i - 1][0])
            );
        }

        for (int i = m - 2; i >= 0; i--) {
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] +
                (restrictions[i + 1][0] - restrictions[i][0])
            );
        }

        int ans = 0;

        for (int i = 0; i < m - 1; i++) {
            int leftPos = restrictions[i][0];
            int leftHeight = restrictions[i][1];

            int rightPos = restrictions[i + 1][0];
            int rightHeight = restrictions[i + 1][1];

            int distance = rightPos - leftPos;

            int maxHeight = (distance + leftHeight + rightHeight) / 2;

            ans = max(ans, maxHeight);
        }

        return ans;
    }
};