class Solution {
public:

    void dfs(int node, vector<int>adjls[], vector<bool>&visi){
        visi[node]=true;
        for(auto it : adjls[node]){
            if(visi[it]==false){
                dfs(it, adjls, visi);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<int>adjls[n];
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }

        vector<bool>visi(n, false);

        for(int i=0; i<n; i++){
            if(visi[i]==false){
                count++;
                dfs(i, adjls, visi);
            }
        }

        return count;
    }
};