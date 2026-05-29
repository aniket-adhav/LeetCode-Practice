class Solution {
public:
    int minElement(vector<int>& nums) {
        
        int n = nums.size();

        for(int i=0;i<n;i++){
            string s = to_string(nums[i]);
            int x = s.size()-1;
            int sum = 0;
            while(x>=0){
                int a = s[x--]-'0';
                sum+=a;
            }

            nums[i]=sum;
        }

        int mini = INT_MAX;
        for(int i = 0; i<n;i++){
            if(nums[i]<mini) mini = nums[i];
        }

        return mini;
    }
};