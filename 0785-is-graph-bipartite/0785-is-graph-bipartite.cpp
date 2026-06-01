class Solution {
public:
    bool solve(int node, int color, vector<int> &colors, vector<vector<int>> &adj){
        colors[node] = color;

        for(auto it: adj[node]){
            if(colors[it] == -1){
                if(solve(it, !color, colors, adj) == false){
                    return false;
                }
            }
            else{
                if(colors[it] == color){
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);

        for(int i=0; i<n; i++){
            if(colors[i] == -1){
                if(solve(i, 0, colors, graph) == false){
                    return false;
                }
            }
        }
        return true;
    }
};