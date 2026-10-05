class Solution {
public:
    int func(string& s,int l,int r) 
    {
        if(r-l==1) return 1;
        int balance=0;
    
        for(int i=l;i<=r;i++) 
        {
            if(s[i]=='(') balance++;
            else balance--;
            if(balance==0) 
            {
                if(i==r) return 2*func(s,l+1,r-1); 
                return func(s,l,i)+func(s,i+1,r);
            }
        }
        return 0;
    }
    int scoreOfParentheses(string s) {
        return func(s,0,s.size()-1);
    }
}; 