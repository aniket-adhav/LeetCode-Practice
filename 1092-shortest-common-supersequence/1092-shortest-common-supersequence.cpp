// class Solution {
// public:

//     string solveUsingMem(string& str1, string& str2, int i, int j,
//                          vector<vector<string>>& dp) {

//         // base case
//         if(i >= str1.length()) {
//             return str2.substr(j);
//         }

//         if(j >= str2.length()) {
//             return str1.substr(i);
//         }

//         if(dp[i][j] != "") {
//             return dp[i][j];
//         }

//         string ans = "";

//         // match
//         if(str1[i] == str2[j]) {

//             ans = str1[i] +
//                   solveUsingMem(str1, str2, i + 1, j + 1, dp);
//         }
//         else {

//             // take character from str1
//             string first = str1[i] +
//                            solveUsingMem(str1, str2, i + 1, j, dp);

//             // take character from str2
//             string second = str2[j] +
//                             solveUsingMem(str1, str2, i, j + 1, dp);

//             if(first.length() <= second.length())
//                 ans = first;
//             else
//                 ans = second;
//         }

//         return dp[i][j] = ans;
//     }

//     string shortestCommonSupersequence(string str1, string str2) {

//         int n = str1.size();
//         int m = str2.size();

//         vector<vector<string>> dp(
//             n, vector<string>(m, "")
//         );

//         return solveUsingMem(str1, str2, 0, 0, dp);
//     }
// };

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Find LCS
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                if(str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Build the shortest common supersequence
        string ans = "";

        int i = n;
        int j = m;

        while(i > 0 && j > 0) {

            if(str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1];
                i--;
                j--;
            }
            else if(dp[i - 1][j] >= dp[i][j - 1]) {
                ans += str1[i - 1];
                i--;
            }
            else {
                ans += str2[j - 1];
                j--;
            }
        }

        // Add remaining characters
        while(i > 0) {
            ans += str1[i - 1];
            i--;
        }

        while(j > 0) {
            ans += str2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};