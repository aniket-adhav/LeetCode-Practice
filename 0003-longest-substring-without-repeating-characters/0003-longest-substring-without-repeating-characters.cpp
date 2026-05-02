class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==1) return 1;
        unordered_set<char>st;
        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
            if(st.find(s[j])!=st.end()){
                ans=max(ans,j-i);
                while(i<j){
                    if(s[i]==s[j]){
                        st.erase(s[i]);
                        i++;
                        break;
                    }
                    st.erase(s[i]);
                    i++;
                }
            }
            st.insert(s[j]);
            j++;
        }
        ans=max(ans,j-i);
        return ans;
    }
};