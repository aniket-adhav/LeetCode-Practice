class Solution {
public:
    vector<int> validSequence(
        string s1,
        string s2) {

        int n = s1.size();
        int m = s2.size();

        
        int j = m - 1;

        vector<int> suffix(n + 1, m);

       
        for (int i = n - 1; i >= 0; i--) {

            suffix[i] = suffix[i + 1];

            if (j >= 0 &&
                s1[i] == s2[j]) {

                suffix[i] = j;
                j--;
            }
        }

        j = 0;

        int mismatch = -1;

        for (int i = 0;
            i < n && j < m;
            i++) {

            if (s1[i] == s2[j]) {

                j++;
            }

            else if (suffix[i + 1] <= j + 1) {

                mismatch = j;
                break;
            }
        }

        vector<int> ans;

        j = 0;

        for (int i = 0;
            i < n && j < m;
            i++) {

            if (j == mismatch) {

                ans.push_back(i);
                j++;
            }

            else if (s1[i] == s2[j]) {

                ans.push_back(i);
                j++;
            }
        }

        if (ans.size() < m)
            return {};

        return ans;
    }
};