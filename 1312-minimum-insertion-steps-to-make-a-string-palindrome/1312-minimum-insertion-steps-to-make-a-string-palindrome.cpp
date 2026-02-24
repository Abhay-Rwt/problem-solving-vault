class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        // dp[i][j] = longest common subsequence in s1[0...i-1] and s2[0...j-1]

        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
            dp[0][i] = 0;
        }

        string t = s;
        reverse(s.begin(), s.end());

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        int lcs = dp[n][n];

        return n - lcs;
    }
};