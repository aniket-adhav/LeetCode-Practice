class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long MOD = 1e9 + 7;

        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<long long> possibleHeights;
        for (int i = 0; i < hFences.size(); i++)
            for (int j = i + 1; j < hFences.size(); j++)
                possibleHeights.insert(hFences[j] - hFences[i]);

        long long maxSideLength = -1;
        for (int i = 0; i < vFences.size(); i++)
            for (int j = i + 1; j < vFences.size(); j++) {
                long long width = vFences[j] - vFences[i];
                if (possibleHeights.count(width))
                    maxSideLength = max(maxSideLength, width);
            }

        return maxSideLength < 0 ? -1
            : (int)(maxSideLength * maxSideLength % MOD);
    }
};