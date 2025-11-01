class DisjointSet{
public:
    vector<int> parent, size;

    DisjointSet(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int U = findUParent(u);
        int V = findUParent(v);
        
        if(U == V) return;

        if(size[U] < size[V]){
            parent[U] = V;
            size[V] += size[U];
        }
        else{
            parent[V] = U;
            size[U] += size[V];
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DisjointSet dsu(26);
        vector<string> later;
        for(int i=0; i<equations.size(); i++){
            string s = equations[i];
            char left = s[0];
            char right = s[3];
            char op = s[1];
            if(op == '!'){
                later.push_back(s);
            }
            else{
                dsu.unionBySize(left - 'a', right - 'a');
            }
        }

        for(string &s: later){
            char left = s[0];
            char right = s[3];
            if(dsu.findUParent(right - 'a') ==  dsu.findUParent(left - 'a')){
                return false;
            }
        }
        
        return true;
    }
};