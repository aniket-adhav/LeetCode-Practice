class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        const long long INF = (long long)1e30;

        vector<pair<int,int>> cells; 
        cells.reserve(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int idx = i * n + j;
                cells.push_back({grid[i][j], idx});
            }
        }
        sort(cells.begin(), cells.end(), [](const auto& a, const auto& b){
            if (a.first != b.first) 
                return a.first > b.first;
            return a.second > b.second; 
        });

        vector<long long> dist(m * n, INF);
        dist[0] = 0;
        long long best = INF;

        for (int t = 0; t <= k; t++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    int idx = i * n + j;
                    long long cur = dist[idx];
                    if (cur >= INF) 
                        continue;
                    if (j + 1 < n) {
                        int ni = idx + 1;
                        long long cost = cur + grid[i][j + 1];
                        if (cost < dist[ni]) 
                            dist[ni] = cost;
                    }
                    if (i + 1 < m) {
                        int ni = idx + n;
                        long long cost = cur + grid[i + 1][j];
                        if (cost < dist[ni]) 
                            dist[ni] = cost;
                    }
                }
            }

            best = min(best, dist[m * n - 1]);
            if (t == k) 
                break;

            vector<long long> nextDist(m * n, INF);
            long long move = INF;

            int p = 0;
            while (p < (int)cells.size()) {
                int val = cells[p].first;
                int q = p;
                long long group_min = INF;
                while (q < (int)cells.size() && cells[q].first == val) {
                    group_min = min(group_min, dist[cells[q].second]);
                    q++;
                }
                move = min(move, group_min);
                for (int t2 = p; t2 < q; t2++) {
                    int idx = cells[t2].second;
                    nextDist[idx] = move;
                }
                p = q;
            }
            dist.swap(nextDist);
        }
        return (best >= INF) ? -1 : (int)best;
    }
};