class Solution {
public:


    const int MOD = 1e9 + 7;
    const int LOG = 18;

    long long power(long long a, long long b) {
        long long res = 1;



        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    int lca(int u, int v, vector<vector<int>>& parent, vector<int>& depth) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];
        for (int i = 0; i < LOG; i++) {
            if (diff & (1 << i)) u = parent[u][i];
        }

        if (u == v) return u;

        for (int i = LOG - 1; i >= 0; i--) {
            if (parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
                u = parent[u][i];
                v = parent[v][i];
            }
        }

        return parent[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> parent(n + 1, vector<int>(LOG, -1));
        vector<int> depth(n + 1, 0);

        queue<int> q;
        q.push(1);

        vector<bool> vis(n + 1, false);
        vis[1] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int child : adj[node]) {
                if (vis[child]) continue;

                vis[child] = true;

                depth[child] = depth[node] + 1;
                parent[child][0] = node;

                q.push(child);
            }
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 1; i <= n; i++) {
                if (parent[i][j - 1] != -1) {
                    parent[i][j] =
                        parent[parent[i][j - 1]][j - 1];
                }
            }
        }

        vector<int> ans;

        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int ancestor = lca(u, v, parent, depth);

            int dist = depth[u] + depth[v] - 2 * depth[ancestor];

            ans.push_back(power(2, dist - 1));
        }

        return ans;
    }
};