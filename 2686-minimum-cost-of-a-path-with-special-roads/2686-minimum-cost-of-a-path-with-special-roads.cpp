class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        if(start[0] == target[0] && start[1] == target[1]) return 0;
        map<pair<int,int>, int> mpp; // for mapping coordinates to node no.
        map<int,pair<int,int>> mpp2;  // for mapping node no. to coordinates

        // 1. mapping all possible coordinates to node no. and vice-versa
        int cnt = 0;
        mpp[{start[0], start[1]}] = cnt;
        mpp2[cnt] = {start[0], start[1]};
        cnt++;

        for(auto it: specialRoads){
            if(mpp.find({it[0], it[1]}) == mpp.end()){
                mpp[{it[0], it[1]}] = cnt;
                mpp2[cnt] = {it[0], it[1]};
                cnt++;
            }

            if(mpp.find({it[2], it[3]}) == mpp.end()){
                mpp[{it[2], it[3]}] = cnt;
                mpp2[cnt] = {it[2], it[3]};
                cnt++;
            }
        }

        if(mpp.find({target[0], target[1]}) == mpp.end()){
            mpp[{target[0], target[1]}] = cnt;
            mpp2[cnt] = {target[0], target[1]};
            cnt++;
        }

        // 2. making adjacency list by considering manhatan distance as edge weight
        vector<vector<pair<int,int>>> adj(cnt); // u -> {d, v}
        for(int u=0; u<cnt; u++){
            for(int v=u+1; v<cnt; v++){
                int d = abs(mpp2[u].first - mpp2[v].first) + abs(mpp2[u].second - mpp2[v].second);
                adj[u].push_back({d, v});
                adj[v].push_back({d, u});
            }
        }

        // 3. now we need to overwrite the edge weight to specailRoads to their specialWeight
        for(int i=0; i<specialRoads.size(); i++){
            int u = mpp[{specialRoads[i][0], specialRoads[i][1]}];
            int v = mpp[{specialRoads[i][2], specialRoads[i][3]}];
            int d = specialRoads[i][4];

            for(int j=0; j<adj[u].size(); j++){
                if(adj[u][j].second == v){
                    adj[u][j].first = min(adj[u][j].first, d);
                }
            }
        }

        // 4. run simple dijkstra's for finding the shortest paths
        vector<int> dist(cnt, 1e8);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, 0});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int u = it.second;

            if(dis > dist[u]) continue;

            for(auto [d, v]: adj[u]){
                if(dist[v] > d + dis){
                    dist[v] = d + dis;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[mpp[{target[0], target[1]}]];
    }
};

















