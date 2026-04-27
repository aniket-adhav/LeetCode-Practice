class Solution {
public:
    int m , n ; 
    
    bool isSafe(int x , int y){
        return x>=0 && y>=0 && x<m && y<n;
    }

    bool dfs(int x , int y , vector<vector<int>>&grid , vector<vector<int>>&visited){
        if(x==m-1 && y==n-1)
        return true;

        visited[x][y]=1;

        if(grid[x][y]==1){
           bool left=isSafe(x,y-1) && visited[x][y-1]==0  && (grid[x][y-1]==1 || grid[x][y-1]==4 || grid[x][y-1]==6) && dfs(x,y-1,grid,visited);
           bool right=isSafe(x,y+1) && visited[x][y+1]==0 && (grid[x][y+1]==1 || grid[x][y+1]==3 || grid[x][y+1]==5) && dfs(x,y+1,grid,visited);
            
           return left || right;
        }

        if(grid[x][y]==2){
           bool up=isSafe(x-1,y) && visited[x-1][y]==0 && (grid[x-1][y]==2 || grid[x-1][y]==4 || grid[x-1][y]==3) && dfs(x-1,y,grid,visited);
           bool down=isSafe(x+1,y) && visited[x+1][y]==0 && (grid[x+1][y]==2 || grid[x+1][y]==6 || grid[x+1][y]==5) && dfs(x+1,y,grid,visited);
            
           return up || down;
        }

        if(grid[x][y]==3){
           bool left=isSafe(x,y-1) && visited[x][y-1]==0  && (grid[x][y-1]==1 || grid[x][y-1]==4 || grid[x][y-1]==6) && dfs(x,y-1,grid,visited);
           bool down=isSafe(x+1,y) && visited[x+1][y]==0 && (grid[x+1][y]==2 || grid[x+1][y]==6 || grid[x+1][y]==5) && dfs(x+1,y,grid,visited);
            
           return left || down;
        }

        if(grid[x][y]==4){
           bool right=isSafe(x,y+1) && visited[x][y+1]==0 && (grid[x][y+1]==1 || grid[x][y+1]==3 || grid[x][y+1]==5) && dfs(x,y+1,grid,visited);
           bool down=isSafe(x+1,y) && visited[x+1][y]==0 && (grid[x+1][y]==2 || grid[x+1][y]==6 || grid[x+1][y]==5) && dfs(x+1,y,grid,visited);

           return right || down;
        }

        if(grid[x][y]==5){
           bool left=isSafe(x,y-1) && visited[x][y-1]==0  && (grid[x][y-1]==1 || grid[x][y-1]==4 || grid[x][y-1]==6) && dfs(x,y-1,grid,visited);
           bool up=isSafe(x-1,y) && visited[x-1][y]==0 && (grid[x-1][y]==2 || grid[x-1][y]==4 || grid[x-1][y]==3) && dfs(x-1,y,grid,visited);
            
           return left || up;
        }

        if(grid[x][y]==6){
           bool up=isSafe(x-1,y) && visited[x-1][y]==0 && (grid[x-1][y]==2 || grid[x-1][y]==4 || grid[x-1][y]==3) && dfs(x-1,y,grid,visited);
           bool right=isSafe(x,y+1) && visited[x][y+1]==0 && (grid[x][y+1]==1 || grid[x][y+1]==3 || grid[x][y+1]==5) && dfs(x,y+1,grid,visited);
            
           return up || right;
        }

        return false;
    }

    
    bool hasValidPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        vector<vector<int>>visited(m,vector<int>(n,0));

        return dfs(0,0,grid,visited);
    }
};