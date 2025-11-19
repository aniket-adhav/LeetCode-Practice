class Solution {
public:
    // returns total hours needed at given speed
    long long helper(const vector<int>& nums, int speed){
        long long totalHour = 0;
        for (int x : nums) {
            // integer ceil division: (x + speed - 1) / speed
            totalHour += (x + (long long)speed - 1) / speed;
        }
        return totalHour;
    }

    int minEatingSpeed(vector<int>& nums, int h) {
        int n = nums.size();
        int maxEle = *max_element(nums.begin(), nums.end());

        int low = 1;
        int high = maxEle;
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalHour = helper(nums, mid);

            if (totalHour <= (long long)h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
