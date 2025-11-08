class Solution {
    int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size(), best[51][51] = {0};
        priority_queue<array<int, 3>> pq;
        pq.push({health - grid[0][0], 0, 0});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int h = it[0];
            int row = it[1];
            int col = it[2];

            if(row == n-1 && col == m-1) return true;

            for(int k=0; k<4; k++){
                int nrow = row + dir[k][0];
                int ncol = col + dir[k][1];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                && best[nrow][ncol] < h - grid[nrow][ncol]){
                    best[nrow][ncol] = h - grid[nrow][ncol];
                    pq.push({best[nrow][ncol], nrow, ncol});
                }
            }
        }

        return false;
    }
};