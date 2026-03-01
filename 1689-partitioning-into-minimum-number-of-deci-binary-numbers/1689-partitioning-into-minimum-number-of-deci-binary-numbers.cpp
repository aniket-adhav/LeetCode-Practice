class Solution {
public:
    int minPartitions(string n) {
        for(char d = '9'; d >= '1'; d--) {
            if(n.find(d) != string::npos)
                return d - '0';
        }
        return 0;
    }
};