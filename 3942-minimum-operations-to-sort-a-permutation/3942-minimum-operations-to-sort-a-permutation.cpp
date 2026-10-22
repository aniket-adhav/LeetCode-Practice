class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
    
        for(int i = 0; i < n; i++){
            int diff = abs(nums[i] - nums[(i + 1) % n]);
            if(diff != 1 && diff != n - 1) return -1;
        }
        int j = 0;
     
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                j = i;
            }
        }
        
        if(j == 0 && nums[n - 1] == n - 1) return 0;
        if(nums[(j + 1) % n] == 1){
            
            return min(j, n - j + 2);
        }else {
            
            return min(j + 2, n - j);
        }
        return -1;
    }
};