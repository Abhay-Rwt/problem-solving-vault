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

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return minOps(n, m, word1, word2, dp);
    }
};