class Solution {
public:
    void helper(vector<string>&ans,int open,int close,int n,string s){
        if(close==n){
            ans.push_back(s);
            return;
        }
        if(open < n) helper(ans,open+1,close,n,s+'(');
        if(close < open) helper(ans,open,close+1,n,s+')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        
        helper(ans,0,0,n,"");
        return ans;
    }
};