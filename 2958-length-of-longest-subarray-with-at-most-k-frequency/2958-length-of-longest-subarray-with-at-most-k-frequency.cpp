class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mp;
        if(n==1) return 1;

        int left = 0;
        int maxlen = 0;

        for(int i=0; i<n; i++){

             mp[nums[i]]++;

            while(mp[nums[i]]>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0) mp.erase(nums[left]);
                left++;
            }

           maxlen = max(i-left+1, maxlen);

        }

        return maxlen;
    }
};