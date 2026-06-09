class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();

        long long maxi = INT_MIN;
        long long mini = INT_MAX;

        for(int i=0; i<n; i++){
            if(nums[i]>maxi) maxi=nums[i];
            if(nums[i]<mini) mini=nums[i];
        }

        ans = (maxi-mini)*k;

        return ans;
    }
};