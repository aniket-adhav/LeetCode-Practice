class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 2, count = 2;
        for (int i = 2; i < n; i++){
            count = nums[i] == nums[i-1] + nums[i-2] ? count + 1 : 2;
            ans = max(ans, count);
        }
        return ans;
    }
};