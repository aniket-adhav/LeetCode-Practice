class Solution {
public:
    int minLengthAfterRemovals(string s) {
       
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (!st.empty() && (st.top() == 'a' && s[i] == 'b')) {
                st.pop();
            } else if (!st.empty() && (st.top() == 'b' && s[i] == 'a')) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        return st.size();
     
    }
};