class Solution {
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        vector<int> used(tiles.size(), 0);
        int result = 0;
        backtrack(tiles, used, 0, result);
        return result;
    }
    
    void backtrack(string& tiles, vector<int>& used, int pos, int& result) {
        if (pos > 0) {
            result++;
        }
        for (int i = 0; i < tiles.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && tiles[i] == tiles[i-1] && !used[i-1]) continue;
            used[i] = 1;
            backtrack(tiles, used, pos + 1, result);
            used[i] = 0;
        }
    }
};