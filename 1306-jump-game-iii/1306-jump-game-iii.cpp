class Solution {
public:
    bool dfs(vector<int>& arr,vector<int>& vis,int n, int start){
        if(start >= n || start < 0) return false;
        vis[start] = 1;

        if(arr[start] == 0) return true;

        int l = start - arr[start];
        int r = start + arr[start];
        
        bool left = false;
        bool right = false;
        if(l >= 0){
            if(!vis[l]){
                left = dfs(arr,vis,n,l);
            }
        }
        if(r < n){
            if(!vis[r]){
                right = dfs(arr,vis,n,r);
            }
        }
        return left || right;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n,0);
        return dfs(arr,vis,n,start);
    }
};