class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i=0;
        bool ans=true;
        if(nums[i]>=nums[i+1] || nums.size()<=3){
            return false;
        }
        while(i<nums.size()-1 && nums[i]<nums[i+1]){
            ans=false;
            i++;
        }
        while(i<nums.size()-1 && nums[i]>nums[i+1]){
            ans=false;
            i++;
        }
        while(i<nums.size()-1){
            if(nums[i]>=nums[i+1]){
                return false;
            }else {
                ans=true;
            }
            i++;
        }
        return ans;

    }
};