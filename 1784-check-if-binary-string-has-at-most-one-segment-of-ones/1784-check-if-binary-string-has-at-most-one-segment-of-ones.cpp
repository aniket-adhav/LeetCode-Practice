class Solution {
public:
    bool checkOnesSegment(string s) {
        int st = 0;
        for(char c : s){
            if(st == 0 and c == '1') st = 1;
            else if(st == 1 and c == '0') st = 2;
            else if(st == 2 and c == '1') return false;
        }
        return true;
    }
};