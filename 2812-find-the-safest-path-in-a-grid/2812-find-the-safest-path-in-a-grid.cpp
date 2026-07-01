class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();


        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;

        vector<vector<int>> safeness(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        
        for (int i = 0; i < n; i++) {
            
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    safeness[i][j] = 0;
                }
            }
        }
        
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && safeness[nr][nc] == -1) {
                    safeness[nr][nc] = safeness[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        
        auto isValid = [&](int minSafe) {
            if (safeness[0][0] < minSafe || safeness[n-1][n-1] < minSafe) return false;
            queue<pair<int, int>> bfs_q;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            
            bfs_q.push({0, 0});
            visited[0][0] = true;
            
            while (!bfs_q.empty()) {
                auto [r, c] = bfs_q.front(); bfs_q.pop();
                if (r == n - 1 && c == n - 1) return true;
                
                for (auto& d : dirs) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] && safeness[nr][nc] >= minSafe) {
                        visited[nr][nc] = true;
                        bfs_q.push({nr, nc});
                    }
                }
            }
            return false;
        };

        int low = 0, high = n * 2, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};