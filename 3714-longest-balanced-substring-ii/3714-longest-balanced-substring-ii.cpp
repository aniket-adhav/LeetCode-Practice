class Solution {
public:
    typedef pair<int,int> pii;
    int take3(string s){
        map<pii, int> mappa;
        int a = 0, b = 0, c = 0, maxi = 1;
        mappa[{0, 0}] = -1;
        for(int i = 0;i<s.size();i++){
            if(s[i] == 'a')
                a++;
            else if(s[i] == 'b')
                b++;
            else c++;
            pii p = {b - a, c - b};
            if(mappa.find(p) != mappa.end())
                maxi = max(maxi, i - mappa[p]);
            else
                mappa[p] = i;
        }
        return maxi;
    }
    int take2(char a, char b, char c, string s){
        int bal = 0, maxCons = 0, n = s.size();
        int i = 0, j = 0, maxi = 1, cntCons = 0;
        map<int, int> mappa;
        mappa[0] = -1;
        while(j < n){
            if(s[j] == c){
                mappa.clear();
                mappa[0] = j;
                j++;
                cntCons++;
                bal = 0;
                maxCons = max(maxCons, cntCons);
                continue;
            }
            cntCons = 0;
            if(s[j] == a)
                bal++;
            else
                bal--;
            if(mappa.find(bal) != mappa.end())
                maxi = max(maxi, j - mappa[bal]);
            else
                mappa[bal] = j;
            j++;
        }
        return max(maxi, maxCons);
    }
    int longestBalanced(string s) { 
        vector<int> results = {
            take3(s),
            take2('a', 'b', 'c', s),
            take2('b', 'c', 'a', s),
            take2('c', 'a', 'b', s)
        };
        return *max_element(results.begin(), results.end());
    }
};