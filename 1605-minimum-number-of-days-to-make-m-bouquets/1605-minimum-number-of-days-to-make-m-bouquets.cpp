class Solution {
public:

    bool isPossible(vector<int>& nums,int days, int m, int k){
        int noofb = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=days){
                count++;
            }
            else{
                noofb+=(count/k);
                count=0;
            }
        }

        noofb+=(count/k);

        return noofb>=m;
    }
    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size();
       long long x = m * 1ll * k * 1ll;
        if(x>n) return -1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
        }
        int low = mini;
        int high = maxi;
        int ans = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isPossible(nums,mid,m,k)==true){
                ans = mid;
                high = mid-1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};