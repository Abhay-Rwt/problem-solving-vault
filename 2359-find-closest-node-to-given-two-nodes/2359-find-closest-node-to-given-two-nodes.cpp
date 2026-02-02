class Solution {
public:
    vector<int> shortestDistance(int node, int size, vector<vector<pair<int,int>>> &adj){
        vector<int> dist(size, 1e8);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        pq.push({0, node});
        dist[node] = 0;

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();

            int u = p.second;
            int d = p.first;

            if(adj[u].empty()) continue;

            for(auto &it: adj[u]){
                int v = it.first;
                int e = it.second;
                if(dist[v] > d + e){
                    dist[v] = d + e;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int size = edges.size();

        vector<vector<pair<int,int>>> adj(size);
        for(int i=0; i<size;i++){
            int u = i;
            int v = edges[i];
            if(v == -1) continue;
            adj[u].push_back({v, 1});
        }

        vector<int> dist1toN = shortestDistance(node1, size, adj);
        vector<int> dist2toN = shortestDistance(node2, size, adj);

        int ans = 1e8;
        int node = -1;

        for(int i=0; i<size; i++){
            if(ans > max(dist1toN[i] , dist2toN[i]))
            {
                ans = max(dist1toN[i], dist2toN[i]);
                node = i;
            }
        }

        return node;
    }
};