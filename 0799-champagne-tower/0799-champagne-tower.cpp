class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> prev_row(1, poured);
        for (int row = 1; row <= query_row; row++) {
            vector<double> curr_row(row + 1, 0.0);
            for (int i = 0; i < row; i++) {
                double remaining = prev_row[i] - 1.0;
                if (remaining > 0) {
                    curr_row[i] += 0.5 * remaining;
                    curr_row[i + 1] += 0.5 * remaining;
                }
            }
            prev_row = curr_row;
        }
        return min(1.0, prev_row[query_glass]);
    }
};