class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        const int n=nums.size();
        bitset<2001> hasX=0;
        int k=0;
        for(int x: nums){
            if (hasX[x]) continue;
            k++;
            hasX[x]=1;
        }
        int freq[2001]={0}, cnt=0, winCnt=0;
        for(int l=0, r=0; r<n; r++){
            const int x=nums[r];
            if (freq[x]++==0) winCnt++;
            int l0=l;
            for(;l<=r && winCnt==k; l++)
                if (--freq[nums[l]]==0) winCnt--;
            cnt+=(n-r)*(l-l0);// update cnt
        }
        return cnt;
    }
};