class Solution {
public:
    string trimTrailingVowels(string s) {
        int n = s.length();
        while(s[n-1] == 'a' |s[n-1] == 'e'|s[n-1] == 'i' |s[n-1] == 'o' |s[n-1] == 'u'){
            s.pop_back();
            n--;
            if(n==0) break;
        }
        return s;
    }
};