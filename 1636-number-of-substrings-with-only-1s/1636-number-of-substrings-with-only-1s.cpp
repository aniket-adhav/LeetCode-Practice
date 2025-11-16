class Solution {
public:
    int numSub(string s) {
        int n = s.size();
        long long ans = 0;
        long long count = 0;
        int i=0;
        while(i<n){
            if(s[i]=='1'){
                count++;
            }
            else if(count>0){
                ans+=(count*(count+1)/2);
                count=0;
            }
            i++;
        }

        if(count>0){
            ans+=(count*(count+1)/2);
        }
        
        if(ans<pow(10,9) + 7){
            return (int)ans;
        }
        return ans%1000000007;
    } 
};