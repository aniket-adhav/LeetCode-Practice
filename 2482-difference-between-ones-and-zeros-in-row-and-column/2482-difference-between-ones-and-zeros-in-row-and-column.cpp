class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<int> col1s(col,0);
        vector<int> row1s(row,0);

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    row1s[i]+=1;
                    col1s[j]+=1;
                }
            }
        }

        vector<vector<int>> diff(row,vector<int>(col,0));

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                diff[i][j]= col1s[j]+row1s[i] - (row-row1s[i])-(col-col1s[j]);
            }
        }
        return diff;

    }
};