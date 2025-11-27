class Solution {
private:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i == 0){
            while(j >= 0){
                if(s1[0] == s2[j]) return 1;
                j--;
            }
            return 0;
        }

        if(j == 0){
            while(i >= 0){
                if(s1[i] == s2[0]) return 1;
                i--;
            }
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        // if both matced
        if(s1[i] == s2[j]) return dp[i][j] =  1 + solve(i-1, j-1, s1, s2, dp);

        return dp[i][j] = max(solve(i-1, j, s1, s2, dp), solve(i, j-1, s1, s2, dp));
    }

public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string s1 = s;
        reverse(s.begin(), s.end());

        // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        vector<int> prev(n+1, 0), curr(n+1, 0);
        
        // return solve(n-1, n-1, s1, s, dp);

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s[j-1]){
                    curr[j] = prev[j-1] + 1;
                }
                else{
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }

        return prev[n];
    }
};