class Solution {
public:
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int pre = 0;
        vector<int> gcd1;
        vector<int> gcd2;
        for(int i : nums){
            pre = max(pre,i);
            int g = gcd(i,pre);
            gcd1.push_back(g);
        }
        sort(gcd1.begin(), gcd1.end());
        int i = 0;
        int j = gcd1.size()-1;
        while(i < j){
            int g2 = gcd(gcd1[i],gcd1[j]);
            gcd2.push_back(g2);
            i++;
            j--;
        }
        long long sum = 0;
        for(int i : gcd2){
            sum+=i;
        }
        return sum;
    }
};