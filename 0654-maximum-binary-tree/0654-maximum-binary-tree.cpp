class Solution {
public:
TreeNode* fun(int l , int r ,vector<int>& nums ){
    if(l>r){return NULL;}
    int maxi = INT_MIN;int p;
    for(int i =l ; i<=r ;i++){if(maxi<nums[i]){p=i;};maxi=max(maxi,nums[i]);}
    TreeNode* node = new TreeNode(maxi);
    node->left=fun(l,p-1,nums);
    node->right=fun(p+1,r,nums);
    return node;
}
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return fun(0,n-1,nums);
    }
};