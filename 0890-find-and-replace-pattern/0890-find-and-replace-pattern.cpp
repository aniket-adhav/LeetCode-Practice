class Solution {
public:
    void createMap(string& str) {

        char start = 'a';
        char mapping[256] = {0};
        for (auto ch : str) {
            if (mapping[ch] == 0) {
                mapping[ch] = start;
                start++;
            }
        }
        for(int i =0;i<str.length();i++){
            char ch = str[i];
            str[i] = mapping[ch];
        }
    }
    vector<string> findAndReplacePattern(vector<string>& words,string pattern) {
        createMap(pattern);
        vector<string>ans;

        for(auto str:words){
            string temp = str;
            createMap(temp);
            if(temp==pattern){
                ans.push_back(str);
            }
        }
        return ans;

    }
};