class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return 1;
        if(i > 0 && j == 0) return 0;
        if(i == 0 && j > 0){
            while(j > 0 && p[j-1] == '*') j--;
            return j == 0 ? 1 : 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1] == p[j-1]){
            return dp[i][j] = solve(i-1, j-1, s, p, dp);
        }
        
        if(p[j-1] == '*'){
            return dp[i][j] = ( solve(i-1, j, s, p, dp) || solve(i-1, j-1, s, p, dp) || 
            solve(i, j-1, s, p, dp)); // use nd don't use *
        }
        else if(p[j-1] == '?'){
            return dp[i][j] = solve(i-1, j-1, s, p, dp); // use ?
        }
        else{
            return dp[i][j] = false;
        }
    }

    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1));

        // return solve(n, m, s, p, dp);

        for(int i=0; i<=n; i++) dp[i][0] = 0;
        for(int j=0; j<=m; j++){
            int it = j;
            while(it > 0 && p[it-1] == '*') it--;
            dp[0][j] = (it == 0) ? 1 : 0;
        }
        dp[0][0] = 1;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == p[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    if(p[j-1] == '*'){
                        dp[i][j] = ( dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1] ); // used, not used, skipped
                    }
                    else if(p[j-1] == '?'){
                        dp[i][j] = dp[i-1][j-1]; // used ?
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
            }
        }

        return dp[n][m];
    }
};