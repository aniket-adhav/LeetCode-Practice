class Solution {
public:
    int helper(vector<int>& prices, int i, int buy, int cap, vector<vector<vector<int>>>&dp){
        if(cap==0) return 0;
        if(i==prices.size()) return 0;

        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];

        int profit = 0;

        if(buy){
            int take = -prices[i] + helper(prices, i+1, 0, cap, dp);
            int nottake = 0 + helper(prices, i+1, 1, cap, dp);
            profit = max(take, nottake);
        }

        else{
            int selltake = prices[i] + helper(prices, i+1, 1, cap-1, dp);
            int sellnottake = 0 + helper(prices, i+1, 0, cap, dp);
            profit = max(selltake, sellnottake);
        }

        dp[i][buy][cap] = profit;
        return dp[i][buy][cap];

    }
    int maxProfit(vector<int>& prices) {

        vector<vector<vector<int>>>dp(prices.size()+1, vector<vector<int>>(2, vector<int>(3, -1)));

        return helper(prices, 0, 1, 2, dp);
    }
};