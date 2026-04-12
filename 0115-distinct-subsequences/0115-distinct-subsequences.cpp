class Solution {
public:
    int solve(int ind1, int ind2, string &s, string &t, vector<vector<int>> &dp){
        if(ind2 == 0){
            return 1;
        }
        if(ind1 == 0){
            return 0;
        }
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        if(s[ind1-1] == t[ind2-1]){
            int take = solve(ind1-1, ind2-1, s, t, dp);
            int nottake = solve(ind1-1, ind2, s, t, dp);
            return dp[ind1][ind2] = take + nottake;
        }
        else{
            int nottake = solve(ind1-1, ind2, s, t, dp);
            return dp[ind1][ind2] = nottake;
        }   
    }

    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<long long> prev(m+1, 0), curr(m+1, 0);
        // return solve(n, m, s, t, dp);

        prev[0]=1;
        curr[0]=1;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = prev[j-1] + prev[j];
                }
                else{
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};