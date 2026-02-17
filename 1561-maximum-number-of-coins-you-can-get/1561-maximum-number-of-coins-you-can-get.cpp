class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int sum=0;
        sort(piles.begin(),piles.end());
        int count=0;
        int i=piles.size()-2;
        while(i>=0)
        {
            count++;
            sum+=piles[i];
            i-=2;
            if(count==piles.size()/3) break;
        }
        return sum;
    }
};