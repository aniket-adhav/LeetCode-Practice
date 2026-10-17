class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int n=nums.size();

        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++) {
            mp[nums[i]] = i;
        }

        sort(nums.begin(), nums.end(), [](int num1, int num2) {

            auto digitSum = [](int num) {

                int sum = 0;
                while(num>0) {

                    sum+=num%10;
                    num/=10;
                }

                return sum;
            };

            int sum1 = digitSum(num1);
            int sum2 = digitSum(num2);

            if(sum1 != sum2) {
                return sum1 < sum2;
            }

            return num1 < num2; 
        });

        int swapCnt = 0;
        vector<bool> vis(n, false);

        for(int i=0; i<n;i++) {
            
            if(vis[i] == true) continue;

            int currIdx = mp[nums[i]];

            vis[currIdx] = true;

            while(currIdx != i) {
                swapCnt++;
                currIdx = mp[nums[currIdx]];
                vis[currIdx] = true;
            }

        }

        return swapCnt;
    }
};