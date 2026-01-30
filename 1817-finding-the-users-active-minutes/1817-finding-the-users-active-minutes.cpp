class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        int i;
        vector<int> temp;
        vector<int> ans(k, 0);
        sort(logs.begin(), logs.end());
        temp.push_back(logs[0][1]);
        for(i=1 ; i<logs.size() ; i++)
        {
            if(logs[i][0]==logs[i-1][0] && count(temp.begin(), temp.end(), logs[i][1])==0)
            {
                temp.push_back(logs[i][1]);                
            }
            else if(logs[i][0]!=logs[i-1][0])
            {
                ans[temp.size()-1] += 1;
                temp.clear();
                temp.push_back(logs[i][1]);
            }
        }
        ans[temp.size()-1] += 1;
        return ans;
    }
};