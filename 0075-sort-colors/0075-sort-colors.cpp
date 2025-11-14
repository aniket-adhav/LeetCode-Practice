class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low = 0; //0
        int mid = 0; //1
        int hi = n-1; //2

        while(mid<=hi){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1) mid++;
            else{
                swap(nums[mid],nums[hi]);
                hi--;
            }
        }
    }
};