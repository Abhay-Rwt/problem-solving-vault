class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1, 0);
        for(auto &it: trust){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        for(int i=1; i<=n; i++){
            if(indegree[i] == n-1 && adj[i].empty()){
                return i;
            }
        }
        return -1;
    }
};