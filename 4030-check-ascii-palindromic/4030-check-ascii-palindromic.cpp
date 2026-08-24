class Solution {
public:
    string decimalToBinary(int decimalNumber) {
        if (decimalNumber <= 0) return "00000000";

        string binaryString = "";

        while (decimalNumber > 0) {
            int remainder = decimalNumber % 2;
            binaryString += to_string(remainder);
            decimalNumber /= 2;
        }

        while (binaryString.size() < 8) {
            binaryString += "0";
        }

        reverse(binaryString.begin(), binaryString.end());

        return binaryString;
    }

    bool isPalindromic(std::string s) {
        string binary = "";
        for (char c : s) {
            binary += decimalToBinary((int)c);
        }
        int i = 0, j = binary.size() - 1;
        while (i < j) {
            if (binary[i] != binary[j])return false;
            i++;
            j--;
        }
        return true;
    }
};