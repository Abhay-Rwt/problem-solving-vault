class Solution {
    int dir[4][2] = {{1,0}, {0,1}, {0,-1}, {-1,0}};
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> time(n, vector<int> (m, INT_MAX));
        priority_queue<array<int, 4>, vector<array<int, 4>>, greater<array<int, 4>>> pq;
        pq.push({0, 0, 0, 2});

        while(!pq.empty()){
            auto [t, row, col, prev] = pq.top();
            pq.pop();

            if(row == n-1 && col == m-1) return t;

            for(int k=0; k<4; k++){
                int nrow = row + dir[k][0];
                int ncol = col + dir[k][1];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    int curr;
                    if(prev == 2) curr = 1;
                    else curr = 2;

                    if(time[nrow][ncol] > max(t, moveTime[nrow][ncol]) + curr){
                        time[nrow][ncol] = max(t, moveTime[nrow][ncol]) + curr;
                        pq.push({time[nrow][ncol], nrow, ncol, curr});
                    }
                    
                }
            }
        }

        return -1;
    }
};