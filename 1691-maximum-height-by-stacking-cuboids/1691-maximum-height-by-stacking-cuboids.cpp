class Solution {
public:

    bool isSafeToPlace(vector<int>c1, vector<int>c2){
        if(c1[0]<=c2[0] && c1[1]<=c2[1] && c1[2]<=c2[2]){
            return true;
        }
        return false;
    }

    // int solveUsingRec(vector<vector<int>>& cuboids, int curr, int prev){
    //     //basecase
    //     if(curr >= cuboids.size()){
    //         return 0;
    //     }

    //     int incl = 0;
    //     if(prev==-1 || isSafetoPlace(cuboids[curr], cuboids[prev])){
    //         incl = cuboids[curr][2] + solveUsingRec(cuboids, curr+1, curr); 
    //     }

    //     int excl = 0 + solveUsingRec(cuboids, curr+1, prev);

    //     int finalans = max(incl, excl);

    //     return finalans;

    // }

    int solveUsingMem(vector<vector<int>>& cuboids, int curr,int prev,vector<vector<int> >& dp) {
        //base case
        if(curr >= cuboids.size()) {
            return 0;
        }
        if(dp[curr][prev+1] != -1) {
            return dp[curr][prev+1];
        }
        //incl excl patter
        int incl = 0;
        if(prev == -1 || isSafeToPlace(cuboids[prev], cuboids[curr] ) ) {
            incl = cuboids[curr][2] + solveUsingMem(cuboids, curr+1, curr,dp);
        }
        int excl = 0 + solveUsingMem(cuboids, curr+1, prev,dp);
        dp[curr][prev+1] = max(incl,excl);
        return dp[curr][prev+1];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();

        for(auto &cuboid : cuboids){
            sort(cuboid.begin(), cuboid.end());
        }

        sort(cuboids.begin(), cuboids.end());

        int curr = 0;
        int prev = -1;

        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        int ans =  solveUsingMem(cuboids, curr, prev, dp);

        return ans;
    }
};