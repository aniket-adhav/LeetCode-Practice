class Solution {
public:
    int helper(vector<int>& nums, int start, int end, vector<vector<int>>&dp){
        if(start > end) return 0;

        if(dp[start][end] != -1) return dp[start][end];

        int coins = INT_MIN;

        for(int i=start; i<=end; i++){
            coins = max(coins,
                nums[start-1]*nums[i]*nums[end+1]
                + helper(nums, start, i-1, dp) 
                + helper(nums, i+1, end, dp)
            );
        }

        dp[start][end] = coins;
        return dp[start][end];
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        vector<vector<int>>dp(nums.size()+1, vector<int>(nums.size()+1, -1));

        return helper(nums, 1, nums.size()-2, dp);
    }
};