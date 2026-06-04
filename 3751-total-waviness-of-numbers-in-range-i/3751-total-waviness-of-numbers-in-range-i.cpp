class Solution {
public:
    int totalWaviness(int num1, int num2) {
        if(num1<100 && num2<100) return 0;
        if(num1<100 && num2>100) num1=101;
        int ans =0;
        for(int i = num1;i<=num2;i++){
            string s = to_string(i);
            int n = s.size()-2;
            int j=1;
            while(j<=n){
                if((s[j]>s[j+1] && s[j]>s[j-1]) || (s[j]<s[j+1] && s[j]<s[j-1])) ans++;
                j++;
            }
        }

        return ans;
    }
};