class Solution {
public:

    unordered_map<int, int> m;

    bool check(int n){
        bool a = 1;
        int c = 0, l = 0;

        while(n){
            l++;

            
            c += (n % 10 == 0);
            c += (n % 10 == 1);
            c += (n % 10 == 8);

          
            a &= !(m[n % 10]);

            n /= 10;
        }

   
        if(c == l) return 0;

        return a;
    }

    int rotatedDigits(int n) {

    
        m[3] = m[4] = m[7] = 1;

        int ans = 0;

        for(int i = 1; i <= n; i++)
            ans += check(i);

        return ans;
    }
};