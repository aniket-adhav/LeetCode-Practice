class Solution {
public:
    vector<int> pref;

    Solution(vector<int>& w) {
        for (int i = 0; i < w.size(); i++) {
            if (i == 0) pref.push_back(w[0]);
            else pref.push_back(pref.back() + w[i]);
        }
    }
    
    int pickIndex() {
        int sum = pref.back();
        int x = rand() % sum, i = 0;

        while (pref[i] <= x) i++;
        return i;
    }
};