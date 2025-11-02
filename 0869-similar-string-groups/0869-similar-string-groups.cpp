class DisjointSet{
public:
    vector<int> parent, size;

    DisjointSet(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0; i<n; i++) parent[i] = i, size[i] = 1;
    }

    int findUParent(int node){
        if(parent[node] != node) {
            return parent[node] = findUParent(parent[node]);
        }
        return node;
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
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DisjointSet dsu(n);
        unordered_map<string,int> mpp; // { string, index }
        for(int i=0; i<n; i++){
            mpp[strs[i]] = i;
        }

        for(auto &[s, k]: mpp){   
            string temp = s;
            int size = temp.size();
            // swap and check;
            for(int i=0; i<size; i++){
                for(int j=i+1; j<size; j++){
                    swap(temp[i], temp[j]);
                    if(mpp.find(temp) != mpp.end()){
                        dsu.unionBySize(k, mpp[temp]);
                        // cout << k << " and " << mpp[temp] << " are unioned" << endl;
                    }
                    // reverting string back to its intial state;
                    swap(temp[j], temp[i]);
                }
            }
        }

        set<int> st;
        for(auto &[s, k]: mpp){
            st.insert(dsu.findUParent(k));
        }

        return st.size();
    }
};