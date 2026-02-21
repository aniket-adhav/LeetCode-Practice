// Approach - 03 - O(nlogn) & O(n)
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int grp = 0;

        set<int> st;
        for(auto& val:nums){st.insert(val);}

        int range = -1;
        for(auto& val:st){
            if(range < val){
                range = val + k;
                grp++;
            }
        }

        return grp;
    }
};