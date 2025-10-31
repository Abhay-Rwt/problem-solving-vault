class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n, vector<int>(n, 0));
        for(auto &it: roads){
            indegree[it[0]]++;
            indegree[it[1]]++;
            adj[it[0]][it[1]] = 1;
            adj[it[1]][it[0]] = 1;
        }
        int maxRank = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int rank = indegree[i] + indegree[j];
                if(adj[i][j] == 1 || adj[j][i] == 1) rank--;
                maxRank = max(maxRank, rank);
            }
        }
        return maxRank;
    }
};