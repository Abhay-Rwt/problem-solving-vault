class Solution {
private:
    const long long INF = (long long)1e18;
    const int MOD = 1e9+7;

    int dfs(int node, int n, vector<long long> &dist, vector<vector<pair<int,int>>> &adj, vector<int> &dp){
        if(node == n) return 1;
        if(dp[node] != -1) return dp[node];
        long long ans = 0;
        for(auto &pr: adj[node]){
            int v = pr.first;
            if(dist[node] > dist[v]) ans = (ans + dfs(v, n, dist, adj, dp)) % MOD;
        }
        return dp[node] = (int)ans;
    }

public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &e: edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<long long> dist(n+1, INF);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        dist[n] = 0;
        pq.push({0, n});

        while(!pq.empty()){
            auto [d, u] = pq.top(); pq.pop();
            if(d > dist[u]) continue;
            for(auto &pr: adj[u]){
                int v = pr.first;
                int w = pr.second;
                if(dist[v] > d + w){
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        vector<int> dp(n+1, -1);
        return dfs(1, n, dist, adj, dp);
    }
};
