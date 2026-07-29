class Solution {
public:
    int helper(vector<int>& prices, int i, int buy, vector<vector<int>>&dp, int fee){
        if(i==prices.size()) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];

        int profit = 0;

        if(buy==1){
            int take = -prices[i] + helper(prices, i+1, 0, dp, fee);
            int nottake = 0 + helper(prices, i+1, 1, dp, fee);
            profit = max(take, nottake);
        }

        else{
            int selltake = prices[i] + helper(prices, i+1, 1, dp, fee) - fee;
            int sellNottake = 0 + helper(prices, i+1, 0, dp, fee);
            profit = max(selltake, sellNottake);
        }

        dp[i][buy]=profit;

        return dp[i][buy];
    }
    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        vector<vector<int>>dp(n+1, vector<int>(2, -1));
        
        return helper(prices, 0, 1, dp, fee);
              
    }
};