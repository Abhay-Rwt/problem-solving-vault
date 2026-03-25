class DisjointSet{
    public:
    vector<int> parent, size;
    DisjointSet(int _size){
        parent.resize(_size);
        size.resize(_size);
        for(int i=0; i<_size; i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findParent(int node){
        if(parent[node] != node){
            return parent[node] = findParent(parent[node]);
        }
        return parent[node];
    }

    bool unionBySize(int u, int v){
        int parentU = findParent(u);
        int parentV = findParent(v);

        if(parentU == parentV) return false;

        if(size[parentU] <= size[parentV]){
            size[parentV] += size[parentU];
            parent[parentU] = parentV;
        }
        else{
            size[parentU] += size[parentV];
            parent[parentV] = parentU;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet dsu = DisjointSet(n+1);
        vector<int> ans;
        for(int i=0; i<n; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            if(!dsu.unionBySize(u, v)){
                return {u, v};
            }
        }
        return {};
    }
};