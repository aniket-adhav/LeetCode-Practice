class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
       const int MOD = 1e9 + 7; 
       vector<int> store(31,0);
       for(int n : nums){
        for(int i = 0; i<31; ++i){
            if((n>>i) & 1){
                store[i]++;
            }
        }
       }
       long long sum = 0;

       for(int i = 0; i<k; ++i){
        long long cv = 0;
        for(int b = 0; b < 31; ++b){
                if(store[b]>0){
                    cv |= (1LL << b);
                    store[b]--;
                }
            }
            long long sqv = (cv % MOD) * (cv % MOD) % MOD;
            sum = ( sum + sqv) % MOD;
        }
        return sum;
       }
};