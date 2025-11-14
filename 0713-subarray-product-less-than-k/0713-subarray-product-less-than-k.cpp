class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if(k<=1) return 0;

        int n=nums.size();
        int count=0;
        int product=1;
        int start=0;
        int end=0;

        while(end<n){

            //expand window
            product=product*nums[end];
            
            //shrink window
            while(product>=k){
                product/=nums[start];
                start++;
            }

            count+=(end-start+1);
            end++;
        }
        return count;
    }
};