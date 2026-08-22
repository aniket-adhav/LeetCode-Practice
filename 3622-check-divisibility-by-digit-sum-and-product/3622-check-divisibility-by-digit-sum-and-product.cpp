class Solution {
public:
    bool checkDivisibility(int n) {
        int num=n;
        int dsum = 0;
        int prod = 1;

        while(n>0){
            dsum+=n%10;
            prod*=n%10;
            n/=10;
        }

        if(num%(dsum+prod)==0) return true;
        return false;
    }
};