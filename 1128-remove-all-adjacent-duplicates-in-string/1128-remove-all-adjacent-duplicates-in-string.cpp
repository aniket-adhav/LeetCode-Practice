class Solution {
public:
    string removeDuplicates(string s) {
        string ansStr;
        for ( int i = 0; i < s.length();  i++){
            if (!ansStr.empty() && ansStr.back() == s[i]){
                
                ansStr.pop_back();
                
            } else {ansStr.push_back(s[i]); }

        } return ansStr;
    }
};