class Solution {
    int dir[4][2] = {{1,0}, {0,1}, {0,-1}, {-1,0}};
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> time(n, vector<int> (m, INT_MAX));
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        pq.push({0, 0, 0});

        while(!pq.empty()){
            auto [t, row, col] = pq.top();
            pq.pop();

            if(row == n-1 && col == m-1) return t;

            for(int k=0; k<4; k++){
                int nrow = row + dir[k][0];
                int ncol = col + dir[k][1];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                && time[nrow][ncol] > max(t, moveTime[nrow][ncol]) + 1){
                    time[nrow][ncol] = max(t, moveTime[nrow][ncol]) + 1;
                    pq.push({time[nrow][ncol], nrow, ncol});
                }
            }
        }

        return -1;
    }
};