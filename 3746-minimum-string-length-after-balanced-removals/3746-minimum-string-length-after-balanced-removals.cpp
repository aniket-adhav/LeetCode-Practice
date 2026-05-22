class Solution {
public:
    int minLengthAfterRemovals(string s) {
        // method 1 : using stack
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
        // method 2 : no. of a - no. of b ka absolute value
        // method 2:
        // int countA = 0;
        // int countB = 0;
        // for (int i = 0; i < s.size(); i++) {
        //     if (s[i] == 'a')
        //         countA++;
        //     else
        //         countB++;
        // }
        // return abs(countA - countB);
    }
};