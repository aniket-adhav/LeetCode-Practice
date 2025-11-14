class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;

        for(int i=1;i<n;i++){
            nums[i]=nums[i-1]+nums[i];
        }
        
        int count = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==k) count++;
            int rem = nums[i]-k;
            if(mp.find(rem)!=mp.end()){
                count+=mp[rem];
            }
            mp[nums[i]]++;
        }
        return count;
    }
};