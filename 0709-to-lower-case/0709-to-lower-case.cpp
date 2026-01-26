class Solution 
{
public:
    string toLowerCase(string s) 
    {
        string b = "";
        for (char a : s){
            a = tolower(a);
            b += a;
        }
        return b;
    }
};