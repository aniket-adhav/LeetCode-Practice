class Solution {
public:
    int mirrorDistance(int n) {
        int x = n;
        string s = to_string(n);
        reverse(s.begin(),s.end());

        x = stoi(s);

        return abs(n-x);
    }
};