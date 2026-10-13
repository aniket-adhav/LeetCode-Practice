class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        for(int i = 0; i < nums.size(); i++){
            nums[i] = abs(nums[i]);
        }

        sort(nums.begin(), nums.end());

        long long sum = 0;
        int n = nums.size();

        for(int j = 0; j < n; j++){

            if(j < n/2){
                sum -= pow(nums[j], 2);
            }
            else{
                sum += pow(nums[j], 2);
            }
        }

        return sum;
    }
};