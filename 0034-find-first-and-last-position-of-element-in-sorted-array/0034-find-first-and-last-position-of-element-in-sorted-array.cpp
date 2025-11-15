class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    vector<int>v;
    int n=nums.size();
    if(n==0){
        return {-1,-1};
    }
    int l=0;
    int h=n-1;
    int first=-1;
    int last=-1;
    while(l<=h){
        int mid=l+(h-l)/2;

        if(nums[mid]==target){
                first=mid;
                h=mid-1;
        }
        else if(nums[mid]<target){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }

    int l1=0;
    int h1=n-1;
    while(l1<=h1){
        int mid1=l1+(h1-l1)/2;
        if(nums[mid1]==target){
                last=mid1;
                l1=mid1+1;
        }
        else if(nums[mid1]<target){
            l1=mid1+1;
        }
        else{
            h1=mid1-1;
        }
    }
    //cout<<first<<","<<last;
    v.push_back(first);
    v.push_back(last);
    return v;
    
    }
};