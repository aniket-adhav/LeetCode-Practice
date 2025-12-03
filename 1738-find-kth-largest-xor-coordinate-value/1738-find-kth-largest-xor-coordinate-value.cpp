class Solution {
public:
    int kthLargestValue(vector<vector<int>>& v, int k) {
        vector<int> xorvalues;  
        int n = v.size(), m = v[0].size();

        vector<vector<int>> xorgrid(n+1, vector<int> (m+1, 0));
    
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int curr = v[i-1][j-1] ^ xorgrid[i-1][j] ^ xorgrid[i][j-1] ^ xorgrid[i-1][j-1];
                xorgrid[i][j] = curr;
                xorvalues.push_back(curr);
            }
        }

        sort(xorvalues.begin(),xorvalues.end()); 
 
        return xorvalues[n*m - k];
    }
};