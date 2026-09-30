class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        int n = s.size();
        vector<int> ans(n);
        int depth = 0;

        for(int i = 0; i < n; i++){
            char ch = s[i];

            if(ch == '('){
                depth++;
                ans[i] = depth % 2;
            }
            else if(ch == ')'){
                ans[i] = depth % 2;
                depth--;
            }
        }

        return ans;
    }
};