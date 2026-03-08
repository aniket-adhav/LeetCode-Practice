class Solution {
public:
    int reverse(int x) {
        long n=0;
        while(x>0 || x<0){
            int a=x%10;
            n=n*10;
            n=n+a;
            x=x/10;
        }
        if(n>=pow(-2,31) && n<=pow(2,31)-1){
            return n;
        }
        else{
            return 0;
        }
    }
};