class Solution {
public:
    int minOps(int ind1, int ind2, string &word1, string &word2, vector<vector<int>> &dp)
    {
        if(ind1 == 0 && ind2 == 0){
            return 0;
        }
        if(ind2 == 0){
            return ind1;
        }
        if(ind1 == 0){
            return ind2;
        }
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        if(word1[ind1-1] == word2[ind2-1]){
            return dp[ind1][ind2] = minOps(ind1-1, ind2-1, word1, word2, dp);
        }

        int replace = 1 + minOps(ind1-1, ind2-1, word1, word2, dp);
        int del = 1 + min(minOps(ind1-1, ind2, word1, word2, dp), minOps(ind1, ind2-1, word1, word2, dp));
        int insert = 1 + min(minOps(ind1, ind2-1, word1, word2, dp), minOps(ind1-1, ind2, word1, word2, dp));

        return dp[ind1][ind2] = min(replace, min(del, insert));
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1));

        // return minOps(n, m, word1, word2, dp);

        for(int i=0; i<=n; i++){
            dp[i][0] = i;
        }
        for(int j=0; j<=m; j++){
            dp[0][j] = j;
        }
        dp[0][0] = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int replace = 1 + dp[i-1][j-1];
                    int del = 1 + min(dp[i-1][j], dp[i][j-1]);
                    // this transition is dup of the above transition actually!
                    // int insert = 1 + min(dp[i-1][j], dp[i][j-1]);

                    dp[i][j] = min(replace, del);
                }
            }
        }

        return dp[n][m];
    }
};