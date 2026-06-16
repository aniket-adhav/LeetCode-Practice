class Solution {
public:
    string processStr(string s) {
        string ans = "";
        int n = s.size();

        for(int i=0; i<n; i++){
            if(s[i]>=97) ans+=s[i];
            else if(s[i]=='*'){
                if(ans.size()>0){
                    int m = ans.size();
                    ans = ans.substr(0, m-1);
                }
            }
            else if(s[i]=='#'){
                if(ans.size()>0){
                    string newstr = ans;
                    ans+=newstr;
                }
            }
            else{
                reverse(ans.begin(), ans.end());
            }
        }

        return ans;
    }
};