class Solution {
public:
    int helper(vector<int>& nums, int target, int i, int sum) {

        if (i == nums.size())
            return sum == target;

        int plus = helper(nums, target, i + 1, sum + nums[i]);
        int minus = helper(nums, target, i + 1, sum - nums[i]);

        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums, target, 0, 0);
    }
};