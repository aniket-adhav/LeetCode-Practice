class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int rp=height.size()-1;
        int lp=0;
        while(lp<rp){
            int w=rp-lp;
            int ht=min(height[lp],height[rp]);
            int water=w*ht;
            ans=max(ans,water);
            if(height[lp]<height[rp]){
                lp++;
            }
            else rp--;
        }
        return ans;
    }
};