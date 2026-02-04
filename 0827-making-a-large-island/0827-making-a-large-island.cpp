class DisjointSet{
public:
    int n;
    vector<int> parent, size;
    DisjointSet(int _n){
        n = _n;
        size.resize(n);
        parent.resize(n);
        for(int i=0; i<n; i++){
            size[i] = 1;
            parent[i] = i;
        }
    }

    int findUParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int pU = findUParent(u);
        int pV = findUParent(v);

        if(pU == pV) return;

        if(size[pU] <= size[pV]){
            parent[pU] = pV;
            size[pV] += size[pU];
        }
        else{
            parent[pV] = pU;
            size[pU] += size[pV];
        }
    }
};

class Solution {
    int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();        
        DisjointSet dsu = DisjointSet(n * m);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){

                    for(int k=0; k<4; k++){
                        int nrow = i + dir[k][0];
                        int ncol = j + dir[k][1];

                        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1){
                            // not connected and though adjacent?
                            int u = i * m + j;
                            int v = nrow * m + ncol;
                            dsu.unionBySize(u, v);
                        }
                    }
                }
            }
        }

        int maxSize = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    unordered_set<int> st;
                    for(int k=0; k<4; k++){
                        int nrow = i + dir[k][0];
                        int ncol = j + dir[k][1];

                        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1){
                            int node = nrow * m + ncol;
                            st.insert(dsu.findUParent(node));
                        }
                    }

                    int currSize = 1; // count itself too

                    for(auto it: st){
                        currSize += dsu.size[it];
                    }

                    maxSize = max(maxSize, currSize);
                }
            }
        }
        // converting 0 -> 1 didn't helped us
        // that means all are 1's
        if(maxSize == 0){
            return n*m;
        }

        return maxSize;
    }
};





















