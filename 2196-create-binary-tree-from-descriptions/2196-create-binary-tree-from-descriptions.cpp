class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& des) {

        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childs;

        int n = des.size();

        for(int i = 0; i < n; i++) {

            vector<int>& v = des[i];

            if(!mp.count(v[0]))
                mp[v[0]] = new TreeNode(v[0]);

            if(!mp.count(v[1]))
                mp[v[1]] = new TreeNode(v[1]);

            if(v[2] == 1) {
                mp[v[0]]->left = mp[v[1]];
            }
            else {
                mp[v[0]]->right = mp[v[1]];
            }

            childs.insert(v[1]);
        }

        for(auto p : mp) {
            if(!childs.count(p.first))
                return p.second;
        }

        return nullptr;
    }
};