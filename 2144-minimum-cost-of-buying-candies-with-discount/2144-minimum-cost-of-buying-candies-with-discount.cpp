class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();

        sort(cost.begin(), cost.end());

        if(n==1) return cost[0];
        if(n==2) return cost[0]+cost[1];

        int ans = 0;
        int i = n-1;
        while(i>=0){
            if(i==0) ans+=cost[i];
            else ans+=cost[i]+cost[i-1];
            i=i-3;
        }

        return ans;
    } 
};