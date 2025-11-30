class Solution {
public:
    int secondHighest(string s) {
        int length = s.size();
        int maxNumber = -1;        // To store the largest digit found
        int secondMaxNumber = -1;  // To store the second largest digit found
        
        // First pass: find the largest digit
        for (int i = 0; i < length; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                maxNumber = max(maxNumber, s[i] - '0');
            }
        }
        
        // Second pass: find the second largest digit smaller than maxNumber
        for (int i = 0; i < length; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                int digit = s[i] - '0';
                if (digit < maxNumber && digit > secondMaxNumber) {
                    secondMaxNumber = digit;
                }
            }
        }
        
        return secondMaxNumber;  // return -1 if no second largest digit found
    }
};