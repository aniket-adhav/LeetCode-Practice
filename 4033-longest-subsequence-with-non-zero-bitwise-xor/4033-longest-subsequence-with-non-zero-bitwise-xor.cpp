class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorr = 0;
        bool flag = false;
        for (int x : nums){
            xorr ^= x;
            if(x>0) flag = true;
        } 

        if(flag==false) return 0;
        if (xorr != 0) return nums.size();
        
        return nums.size() - 1;
    }
};
