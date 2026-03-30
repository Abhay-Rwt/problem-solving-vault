class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int findUParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionBySize(int u, int v) {
        int U = findUParent(u);
        int V = findUParent(v);
        if (U == V) return;
        if (size[U] < size[V]) {
            size[V] += size[U];
            parent[U] = V;
        } else {
            size[U] += size[V];
            parent[V] = U;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        for (auto& stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        DisjointSet dsu(maxRow + maxCol + 2);
        unordered_map<int, int> mpp;

        for (auto& it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            dsu.unionBySize(nodeRow, nodeCol);
            mpp[nodeRow] = 1;
            mpp[nodeCol] = 1;
        }

        int compCnt = 0;
        for (auto& it : mpp) {
            if (dsu.findUParent(it.first) == it.first) {
                compCnt++;
            }
        }

        return stones.size() - compCnt;
    }
};
