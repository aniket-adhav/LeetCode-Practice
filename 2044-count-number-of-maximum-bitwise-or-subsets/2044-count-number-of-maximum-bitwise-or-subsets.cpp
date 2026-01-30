class Solution {
public:
    int countSubsets(int idx, int currOr , vector<int>& nums , int maxOr){
        if(idx == nums.size()){
            return currOr == maxOr ? 1 : 0;
        }

        // Include current number
        int takeCount = countSubsets(idx + 1, currOr | nums[idx], nums, maxOr);
        // Exclude current number
        int notTakeCount = countSubsets(idx + 1, currOr, nums, maxOr);
        
        return takeCount + notTakeCount;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int &num : nums){
            maxOr |= num;
        }
        return countSubsets(0, 0, nums, maxOr);
    }
};