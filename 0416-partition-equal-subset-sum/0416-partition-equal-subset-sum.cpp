class Solution {
public:
    bool helper(vector<int>&nums, int total, int i, vector<vector<int>>&dp){
       
        if(total==0){
            return true;
        }

        if(i>=nums.size()) return 0;

        if(dp[i][total]!=-1) return dp[i][total];

        bool flag1 = false;
        if(nums[i]<=total) flag1 = helper(nums, total-nums[i], i+1, dp);
        bool flag2 = helper(nums, total, i+1, dp);

        dp[i][total] = flag1 || flag2;

        return dp[i][total];



    }
    bool canPartition(vector<int>& nums) {
       int total = 0;

       for(int i=0; i<nums.size(); i++){
            total+=nums[i];
       }

       if(total%2!=0) return false;

       vector<vector<int>>dp(nums.size()+1, vector<int>(total/2+1, -1));

       return helper(nums, total/2, 0, dp);
    }
};