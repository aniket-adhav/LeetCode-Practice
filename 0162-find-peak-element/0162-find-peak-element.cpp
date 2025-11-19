class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // int lo = 0, hi = n - 1;
        // while (lo < hi) {
        //     int mid = lo + (hi - lo) / 2;
        //     if (nums[mid] > nums[mid + 1]) {
        //         hi = mid;
        //     } else {
        //         // Peak is on the right side
        //         lo = mid + 1;
        //     }
        // }
        // return lo;  
        if(n==1) return 0;  
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        int low = 1;
        int high = n-2;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]) return mid;

            else if(nums[mid]>nums[mid-1]) low=mid+1;

            else high=mid-1;
        }
        return -1;
    }
};