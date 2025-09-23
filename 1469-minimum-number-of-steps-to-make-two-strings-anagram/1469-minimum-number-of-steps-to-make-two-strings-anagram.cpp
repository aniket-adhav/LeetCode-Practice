class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>mp1,mp2;
        for(int i=0;i<s.size();i++)mp1[s[i]]++;
        for(int i=0;i<t.size();i++)mp2[t[i]]++;
        int ans=0;
        for(auto it2:mp2)
        {
            if(mp1[it2.first]<it2.second)
            {
                ans=ans+it2.second-mp1[it2.first];
            }
        }
        return ans;

    }
};