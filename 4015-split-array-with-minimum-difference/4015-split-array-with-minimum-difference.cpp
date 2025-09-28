class Solution {
public:
    long long splitArray(vector<int>& nums) {
        using ll = long long;
        ll n=(ll)nums.size(),ans=1e15+9;
        vector<ll>prefix(n,1e15),suffix(n,1e13);
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                prefix[i]=prefix[i-1]+nums[i];
            }else{
               break;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>nums[i+1])
            {
                suffix[i]=nums[i]+suffix[i+1];
            }else{
               break;
            }
        }
        for(int i=1;i<n;i++)
        {
            ans=min(ans,abs(prefix[i-1]-suffix[i]));
        }
        return ans>1e10?-1:ans;
    }
};