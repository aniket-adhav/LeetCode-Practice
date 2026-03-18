class Solution {
public:
    void find(int idx,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&v){
        if(idx==arr.size()){
            if(target==0){
                ans.push_back(v);
            }
            return;
        }
        //pick the element
        if(arr[idx]<=target){
            v.push_back(arr[idx]);
            find(idx,target-arr[idx],arr,ans,v);
            v.pop_back();
        }
        find(idx+1,target,arr,ans,v);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        find(0,target,candidates,ans,v);
        return ans;
    }
};