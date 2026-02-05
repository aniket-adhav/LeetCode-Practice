class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int sz=arr.size();
        vector<int>pre(sz+2,0);
        for(int i=1;i<=arr.size();i++){
            pre[i]=pre[i-1]^arr[i-1];
        }
        int ans=0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(pre[i]==pre[j+1]){
                    ans+=(j-i);
                }
            }
        }
        return ans;
    }
};