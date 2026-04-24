class Solution {
public:
    int furthestDistanceFromOrigin(string m) {
        int n = m.size();

        int cl = 0;
        int cr = 0;
        int cd = 0;
        
        for(int i=0;i<n;i++){
            if(m[i]=='L') cl++;
            else if(m[i]=='R') cr++;
            else cd++;
        }

        if(cl>=cr) return cd + (cl-cr);
        return cd + (cr-cl);
    }
};