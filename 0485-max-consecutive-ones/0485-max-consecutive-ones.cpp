class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int count=0;
        int ans = 0;
        while(i<n){
            if(nums[i]==1){
                count++;
            }
            else{
                ans=max(ans,count);
                count=0;
            }
            i++;
        }
        ans=max(ans,count);
        return ans;
    }
};