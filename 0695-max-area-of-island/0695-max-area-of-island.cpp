class Solution {
private:
    int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    void dfs(int row, int col, int n, int m, int &area, vector<vector<int>> &grid, 
    vector<vector<int>> &vis)
    {
        vis[row][col] = 1;
        area++;

        for(int k=0; k<4; k++){
            int nrow = row + dir[k][0];
            int ncol = col + dir[k][1];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1
            && vis[nrow][ncol] == 0)
            {
                dfs(nrow, ncol, n, m, area, grid, vis);
            }
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    int area = 0;
                    dfs(i, j, n, m, area, grid, vis);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};






