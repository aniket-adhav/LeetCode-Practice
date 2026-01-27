class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) 
    {   
        int n = score.size();
        int m = score[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        vector<pair<int,int>> ind;

        for (int i = 0; i < n; i++) 
        {
            ind.push_back({score[i][k], i});
        }
        sort(ind.rbegin(), ind.rend());

        int a = 0;
        for (auto it : ind) 
        {
            int x = it.second;
            for (int j = 0; j < m; j++) 
            {
                ans[a][j] = score[x][j];
            }
            a++;
        }

        return ans;
    }
};