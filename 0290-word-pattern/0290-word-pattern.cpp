class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> ps;
        unordered_map<string, char> sp;
        vector<string> words;
        string temp = "";

        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                if (!temp.empty()) words.push_back(temp);
                temp = "";
            } else {
                temp += s[i];
            }
        }

        if (words.size() != pattern.size())
            return false;

        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            string word = words[i];
            if ((ps.count(c) && ps[c] != word) || (sp.count(word) && sp[word] != c))
                return false;
            ps[c] = word;
            sp[word] = c;
        }
        return true;
    }
};