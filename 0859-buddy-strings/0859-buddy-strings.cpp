class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length()) return false;
        
        if(s == goal){
            unordered_map<char,int>mpp;
            for(char c : s){
                mpp[c]++;
            }
            for(auto& pair : mpp){
                if(pair.second >= 2){
                    return true;
                }
            }
            return false;
        }

        int first = -1;
        int second = -1;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != goal[i]){
                if(first == -1){
                    first  = i;
                }
                else if(second == -1){
                    second = i;
                }
                else{
                    return false; //more than 2 mismatches found
                }
            }
        }
        return second != -1 && s[first] == goal[second] && goal[first] == s[second];
    }
};