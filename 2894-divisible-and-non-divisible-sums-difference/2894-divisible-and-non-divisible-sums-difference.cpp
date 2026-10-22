class Solution {
public:
    int differenceOfSums(int n, int m) {
        int k = n / m;

        int num2 = m*(k*(k + 1)) / 2;
        int num1 = (n * (n + 1)) / 2 - num2;

        return num1 - num2;
    }
};