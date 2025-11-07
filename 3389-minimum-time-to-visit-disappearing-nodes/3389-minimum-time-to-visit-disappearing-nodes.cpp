class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n, 1e9);

        pq.push({0, 0});
        dist[0] = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int u = it.second;
            int d = it.first;

            if(d > dist[u]) continue;

            for(auto it: adj[u]){
                int v = it.first;
                int e = it.second;

                if(dist[v] > d + e && disappear[v] > d + e){
                    dist[v] = d + e;
                    pq.push({dist[v], v});
                }
            }
        }

        for(int &it: dist){
            if(it == 1e9) it = -1;
        }

        return dist;
    }
};

