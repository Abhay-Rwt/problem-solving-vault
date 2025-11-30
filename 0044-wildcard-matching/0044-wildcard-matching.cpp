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
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return solve(n, m, s, p, dp);
    }
};