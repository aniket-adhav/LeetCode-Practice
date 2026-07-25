class Solution {
public:

    int maxProduct(int n) {
        vector<int>nums;
        while(n>0){
            int x = n%10;
            nums.push_back(x);
            n/=10;
        }

        sort(nums.begin(), nums.end());

        return nums[nums.size()-1]*nums[nums.size()-2];
    }
};