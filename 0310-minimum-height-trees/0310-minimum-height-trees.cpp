class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.empty()){
            vector<int> ans;
            for(int i=0; i<n; i++) ans.push_back(i);
            return ans;
        }
        vector<int> degree(n);
        vector<vector<int>> adj(n);
        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            degree[it[0]]++;
            degree[it[1]]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(degree[i]==1){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int size=q.size();
            ans.clear();

            for(int i=0; i<size; i++){
                int node=q.front();
                ans.push_back(node);
                q.pop();

                for(auto adjNode: adj[node]){
                    degree[adjNode]--;
                    if(degree[adjNode]==1){
                        q.push(adjNode);
                    }
                }
            }
        }
        return ans;
    }
};