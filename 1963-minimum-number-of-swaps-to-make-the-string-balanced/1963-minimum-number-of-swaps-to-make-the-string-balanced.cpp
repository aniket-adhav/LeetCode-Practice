class Solution {
public:
    int minSwaps(string s) {
        int count = 0;
        int minCount = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '[')
                count++;
            else
                count--;
            minCount = min(minCount, count);
        }
        minCount = abs(minCount);
        if (minCount % 2 == 1)
            return (minCount + 1) / 2;
        else
            return minCount / 2;
    }
};