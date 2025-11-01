class DisjointSet{
public:
    vector<int> parent;

    DisjointSet(int n){
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
    }

    int findUParent(int node){
        if(parent[node] != node){
            return parent[node] = findUParent(parent[node]);
        }
        return node;
    }

    void unionByLexico(int u, int v){
        int U = findUParent(u);
        int V = findUParent(v);
        if(U == V) return;

        if(U < V){
            parent[V] = U;
        }
        else{
            parent[U] = V;
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet dsu(26);
        int n = s1.length();
        for(int i=0; i<n; i++){
            int ch1 = s1[i] - 'a';
            int ch2 = s2[i] - 'a';
            dsu.unionByLexico(ch1, ch2);
        }
        string ans;
        for(char &ch: baseStr){
            ans.push_back('a' + dsu.findUParent(ch - 'a'));
        }
        return ans;
    }
};














