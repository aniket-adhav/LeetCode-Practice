class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int i, m, n, j, cnt;

        m = grid.size();
        n = grid[0].size();
        cnt = 0; j=n;

       for(i=0; i<m; i++){
            while(j>0 && grid[i][j-1]<0) j--;
            cnt+= n-j;
       }

       return cnt;
    }
};