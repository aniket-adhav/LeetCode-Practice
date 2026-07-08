class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1000000007;

        int n = s.size();

        vector<long long> prefixSum(n);
        vector<long long> prefixStr(n);
        vector<int> prefixCnt(n);
        vector<long long> power(n + 1);

        power[0] = 1;

        for(int i = 1; i <= n; i++){
            power[i] = (power[i-1] * 10) % MOD;
        }

        prefixSum[0] = s[0]-'0';
        prefixCnt[0] = s[0]!='0';
        prefixStr[0] = s[0]-'0';


        for(int i=1;i<n;i++){

            int digit=s[i]-'0';

            prefixSum[i]=(prefixSum[i-1]+digit)%MOD;

            prefixCnt[i]=prefixCnt[i-1]+(digit!=0);


            if(digit)
                prefixStr[i]=(prefixStr[i-1]*10+digit)%MOD;
            else
                prefixStr[i]=prefixStr[i-1];
        }


        vector<int> ans;


        for(auto &q:queries){

            int l=q[0];
            int r=q[1];


            long long sum=prefixSum[r];

            if(l>0)
                sum=(sum-prefixSum[l-1]+MOD)%MOD;



            int cnt=prefixCnt[r];

            if(l>0)
                cnt-=prefixCnt[l-1];



            long long num=prefixStr[r];


            if(l>0){

                num=(
                    num-prefixStr[l-1]*power[cnt]%MOD+MOD
                )%MOD;
            }


            ans.push_back(num*sum%MOD);
        }


        return ans;
    }
};