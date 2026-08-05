class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> graph(n);

        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
        }

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(k);
        vis[k] = true;

        while (!q.empty()) {

            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        vector<int> ans;

        for (auto &edge : invocations) {

            int u = edge[0];
            int v = edge[1];

            if (!vis[u] && vis[v]) {

                for (int i = 0; i < n; i++)
                    ans.push_back(i);

                return ans;
            }
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};