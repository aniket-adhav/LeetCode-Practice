class Solution {
public:
    struct SegmentTree {
        int n;
        vector<int> st;

        SegmentTree(int n) : n(n) { st.assign(4 * n + 7, 0); }

        void update(int id, int l, int r, int pos, int val) {
            if (pos < l || pos > r)
                return;
            if (l == r) {
                st[id] = val;
                return;
            }
            int m = (l + r) / 2;
            if (pos <= m) {
                update(id * 2 + 1, l, m, pos, val);
            } else {
                update(id * 2 + 2, m + 1, r, pos, val);
            }
            st[id] = max(st[id * 2 + 1], st[id * 2 + 2]);
        }

        int getMax(int id, int l, int r, int u, int v) {
            if (r < u || l > v)
                return 0;
            if (u <= l && r <= v)
                return st[id];
            int m = (l + r) / 2;
            return max(getMax(id * 2 + 1, l, m, u, v),
                       getMax(id * 2 + 2, m + 1, r, u, v));
        }

        void update(int pos, int val) { update(0, 0, n - 1, pos, val); }

        int getMax(int u, int v) { return getMax(0, 0, n - 1, u, v); }
    };
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool> res;
        set<int> s;
        s.insert(0);
        SegmentTree st(50001);
        for (vector<int> q : queries) {
            int type = q[0];
            if (type == 1) {
                int x = q[1];
                auto it = s.lower_bound(x);
                if (it != s.end()) {
                    int aft = *it;
                    st.update(aft, aft - x);
                }
                int pre = *(--it);
                st.update(x, x - pre);
                s.insert(x);
            } else {
                int x = q[1];
                int sz = q[2];

                int d = st.getMax(0, x);
                int d1 = *(--s.lower_bound(x));
                d = max(d, x - d1);
                res.push_back((sz <= d));
            }
        }
        return res;
    }
};