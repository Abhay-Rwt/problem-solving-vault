class Solution {
public:
    int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return 0;
        if(i > 0 && j == 0) return i;
        if(i == 0 && j > 0) return j;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i-1] == word2[j-1]) return dp[i][j] = solve(i-1, j-1, word1, word2, dp);

        int rep = 1 + solve(i-1, j-1, word1, word2, dp);
        int del = 1 + min(solve(i-1, j, word1, word2, dp), solve(i, j-1, word1, word2, dp));
        int ins = 1 + min(solve(i-1, j, word1, word2, dp), solve(i, j-1, word1, word2, dp));

        return dp[i][j] = min(rep, min(del, ins));
    }

    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return solve(n, m, word1, word2, dp);
    }
};