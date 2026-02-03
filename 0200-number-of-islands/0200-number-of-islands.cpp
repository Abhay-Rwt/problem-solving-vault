class DisjointSet{
private:
    int n;
    vector<int> parent, size;
public:
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

int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int size = n * m;
        DisjointSet dsu(size);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int k=0; k<4; k++){
                    int nrow = i + dir[k][0];
                    int ncol = j + dir[k][1];
                    
                    if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && grid[i][j] == '1' && grid[nrow][ncol] == '1'){
                        int u = i * m + j;
                        int v = nrow * m + ncol;

                        dsu.unionBySize(u, v);
                    }
                }
            }
        }


        unordered_set<int> st;
    for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        if(grid[i][j] == '1'){
            int node = i * m + j;
            st.insert(dsu.findUParent(node));
        }
    }
}


        return st.size();
    }
};