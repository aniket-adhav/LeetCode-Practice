class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        if (sum > 9 * num) {
            return "";
        }

        string result;

        int n = sum / 9;
        sum %= 9;

        result.append(n, '9');

        if (sum > 0) {
            result += char('0' + sum);
        }

        result.append(num - result.size(), '0');

        return result;
    }
};