class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // initialize with first three elements' sum (safe since n >= 3 for valid input)
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; ++i) {
            // optional duplicate skip for i to reduce some work
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                // update closest if this sum is nearer target
                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }

                // move pointers like standard 2-pointer for 3-sum
                if (sum < target) {
                    ++j;
                } else if (sum > target) {
                    --k;
                } else {
                    // exact match — cannot do better
                    return target;
                }
            }
        }
        return closestSum;
    }
};
