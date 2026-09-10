class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());

        int i = 1;
        int n = nums.size();

        while (i<n) {
            int temp = i;
            ans.push_back(nums[i]);
            ans.push_back(nums[i - 1]);
            i=temp;
            i += 2;
        }

        if (n%2!=0) {
            ans.push_back(nums[n - 1]);
        }

        return ans;
    }
};