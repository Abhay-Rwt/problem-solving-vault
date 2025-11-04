class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> prob(n, -1e8);
        priority_queue<pair<double,int>> pq;
        
        pq.push({1, start});
        prob[start] = 1;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            double prob_till = it.first;

            for(auto &it: adj[node]){
                int adjNode = it.first;
                double edgeProb = it.second;

                if(prob[adjNode] < edgeProb * prob_till){
                    prob[adjNode] = edgeProb * prob_till;
                    pq.push({prob[adjNode], adjNode});
                }
            }
        }

        return prob[end] == -1e8 ? 0 : prob[end];
    }
};