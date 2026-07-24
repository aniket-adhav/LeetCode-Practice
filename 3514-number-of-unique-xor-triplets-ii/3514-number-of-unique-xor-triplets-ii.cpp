class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<bool>two(2049,false);
        for(auto val1 : nums)
        {
            for(auto val2 : nums)
            {
                int val  = val1^val2;
                two[val]=true;
            }
        }

        vector<bool>three(2049,false);
        int count=0;
        for(int i=0;i<=2048;i++)
        {
            if(!two[i])continue;
            for(auto v : nums)
            {
                if(three[i^v])continue;
                count++;
                three[i^v]=true;
            }
        }
    return count;
    }
};