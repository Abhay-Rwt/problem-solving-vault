class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, 
    vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> mat(26, vector<int>(26, 1e9));
        for(int i=0; i<26; i++) mat[i][i] = 0;

        for(int i=0; i<original.size(); i++){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int c = cost[i];

            mat[u][v] = min(mat[u][v], c);
        }


        for(int k=0; k<26; k++){
            for(int i=0; i<26; i++){
                for(int j=0; j<26; j++){
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }


        long long ans = 0;
        for(int i=0; i<source.length(); i++){
            if(source[i] == target[i]) continue;
            int shortestDist = mat[source[i] - 'a'][target[i] - 'a'];
            if(shortestDist == 1e9) return -1;
            ans = ans + shortestDist;
        }

        return ans;
    }
};