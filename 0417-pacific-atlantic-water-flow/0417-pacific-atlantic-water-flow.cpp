class Solution {
private:
    int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    // for pacific we can only go right and down;
    void pacific(int row, int col, int n, int m, vector<vector<int>> &heights, 
    vector<vector<int>> &vis)
    {
        vis[row][col] = 1;

        if(row + 1 < n && vis[row + 1][col] == 0 
        && heights[row + 1][col] >= heights[row][col]){
            pacific(row+1, col, n, m, heights, vis);
        }
        if(col + 1 < m && vis[row][col + 1] == 0
        && heights[row][col + 1] >= heights[row][col]){
            pacific(row, col+1, n, m, heights, vis);
        }
    }

    // and for atlantic we can only go left and top;
    void atlantic(int row, int col, int n, int m, vector<vector<int>> &heights, 
    vector<vector<int>> &vis)
    {
        vis[row][col] = 1;

        if(row - 1 >= 0 && vis[row - 1][col] == 0 
        && heights[row - 1][col] >= heights[row][col]){
            atlantic(row-1, col, n, m, heights, vis);
        }
        if(col - 1 >= 0 && vis[row][col - 1] == 0
        && heights[row][col - 1] >= heights[row][col]){
            atlantic(row, col - 1, n, m, heights, vis);
        }
    }

    void dfs(int row, int col, int n, int m, vector<vector<int>> &heights, 
    vector<vector<int>> &vis)
    {
        vis[row][col] = 1;
        
        for(int k=0; k<4; k++){
            int nrow = row + dir[k][0];
            int ncol = col + dir[k][1];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0
            && heights[nrow][ncol] >= heights[row][col]){
                dfs(nrow, ncol, n, m, heights, vis);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> vis1(n, vector<int>(m, 0));
        vector<vector<int>> vis2(n, vector<int>(m, 0));

        for(int j=0; j<m; j++){
            if(vis1[0][j] == 0){
                dfs(0, j, n, m, heights, vis1);
            }
            if(vis2[n-1][j] == 0){
                dfs(n-1, j, n, m, heights, vis2);
            }
        }
        for(int i=0; i<n; i++){
            if(vis1[i][0] == 0){
                dfs(i, 0, n, m, heights, vis1);
            }
            if(vis2[i][m-1] == 0){
                dfs(i, m-1, n, m, heights, vis2);
            }
        }

        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis1[i][j] && vis2[i][j]){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};