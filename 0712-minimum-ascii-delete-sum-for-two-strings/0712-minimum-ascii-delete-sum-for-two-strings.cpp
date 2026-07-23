class Solution {
public:
    int helper(string&s1, string&s2, int i, int j, vector<vector<int>>&dp){
        int cost = 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(i==s1.size() || j==s2.size()){

           

            for(int x=i; x<s1.size(); x++){
                cost+=s1[x];
            }

            for(int x=j; x<s2.size(); x++){
                cost+=s2[x];
            }

        }

        else if(s1[i]==s2[j]){
            cost = helper(s1, s2, i+1, j+1, dp);
        }
        else{
            int cost1 = s1[i] + helper(s1, s2, i+1, j, dp);
            int cost2 = s2[j] + helper(s1, s2, i, j+1, dp);
            cost = min(cost1, cost2);
        }

        dp[i][j] = cost;

        return dp[i][j];
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        return helper(s1, s2, 0, 0, dp);
    }
};