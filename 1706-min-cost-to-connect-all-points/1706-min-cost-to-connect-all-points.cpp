class Solution {
private: 
    int manhtan_dist(int x1, int y1, int x2, int y2){
        return abs(x1 - x2) + abs(y1 - y2);
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> vis(n, 0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        pq.push({0, 0});

        int ans = 0;
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();

            if(vis[u]) continue;
            vis[u] = 1;
            ans += d;

            for(int i=0; i<n; i++){
                if(!vis[i]){
                    int man_dist = manhtan_dist(points[u][0], points[u][1], points[i][0], points[i][1]);
                    pq.push({man_dist, i});
                }
            }
        }

        return ans;
    }
};