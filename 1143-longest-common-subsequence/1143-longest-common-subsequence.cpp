class Solution {
private: 
    int solve(int i, int j, int n, string &s, string &t, vector<vector<int>> &dp){
        if(i == 0){
            while(j >= 0){
                if(s[i] == t[j]){
                    return 1;
                }
                else j--;
            }
            return 0;
        }
        if(j == 0){
            while(i >= 0){
                if(s[i] == t[j]){
                    return 1;
                }
                else i--;
            }
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]){
            return dp[i][j] = 1 + solve(i-1, j-1, n, s, t, dp);
        }

        return dp[i][j] = max(solve(i-1, j, n, s, t, dp), solve(i, j-1, n, s, t, dp));
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // return solve(n-1, m-1, n, text1, text2, dp);

        dp[0][0] = (text1[0] == text2[0]);

        // i == 0 {fixing ith index}
        for(int j=1; j<m; j++){
            dp[0][j] = (text1[0] == text2[j]) ? 1 : dp[0][j-1];
        }

        // j == 0 {fixing jth index}
        for(int i=1; i<n; i++){
            dp[i][0] = (text1[i] == text2[0]) ? 1 : dp[i-1][0];
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n-1][m-1];

    }
};