class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int count = 0, mini = INT_MAX;

        for(int i = 0; i < nums1.size(); i++){
            if(nums1[i] % 2 == 0) count++;
            mini = min(mini, nums1[i]);
        }

        if(count != nums1.size() && mini % 2 == 0) return false;

        return true;
    }
};