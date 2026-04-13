class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] == 0) {
                for (int j = i; j <= i + 2; j++) {
                    nums[j] ^= 1;
                }
                count++;
            }
        }

        for (int i = 0; i < nums.size(); i++) if (nums[i] == 0) return -1;
        return count;
    }
};