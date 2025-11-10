class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<array<int, 3>>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2], it[3]});
        }
        vector<int> time(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        time[0] = 0;
        pq.push({0, 0});

        while(!pq.empty()){
            auto [t, u] = pq.top();
            pq.pop();
            if(t > time[u]) continue;
            
            if(u == n-1) return t;

            for(auto [v, st, end]: adj[u]){
                if(t >= st && t <= end){
                    if(time[v] > t + 1){
                        time[v] = t + 1;
                        pq.push({time[v], v});
                    }
                }
                else if(t < st){
                    int waitingTime = st - t;
                    if(time[v] > t + waitingTime + 1){
                        time[v] = t + waitingTime + 1;
                        pq.push({time[v], v});
                    }
                }
            }
        }
        return -1;
    }
};