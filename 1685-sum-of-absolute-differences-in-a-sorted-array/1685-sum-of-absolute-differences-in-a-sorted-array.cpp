class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n =nums.size();
        vector<int> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        int total=prefix[n-1];
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            int left;
            if(i==0) left=0;
            else left=((i)*nums[i])-prefix[i-1];
            int right=((total-prefix[i])-((n-i-1)*nums[i]));
            ans[i]=left+right;
        }
        return ans;
    }
};