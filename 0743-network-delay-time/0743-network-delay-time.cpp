class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto time: times){
            adj[time[0]].push_back({time[1], time[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        vector<int> minTime(n+1, INT_MAX);

        minHeap.push({0, k});
        minTime[k] = 0;

        while(!minHeap.empty()){
            auto it = minHeap.top();
            minHeap.pop();
            int time = it.first;
            int node = it.second;

            if(minTime[node] < time){
                continue;
            }

            for(auto it: adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;

                if(minTime[adjNode] > time + edgeWt){
                    minTime[adjNode] = time + edgeWt;
                    minHeap.push({minTime[adjNode], adjNode});
                }
            }
        }

        int maxi = INT_MIN;
        for(int i=1; i<=n; i++) maxi = max(maxi, minTime[i]);

        return maxi == INT_MAX ? -1 : maxi;
    }
};