class Solution {
public:
    // turn = 1 -> Alice
    // turn = 0 -> Bob
    bool solve(int n, int turn, vector<vector<int>> &dp){
        if(n == 1) return false;
        if(dp[n][turn] != -1) return dp[n][turn];
        for(int x=1; x<n; x++){
            if(n % x == 0){
                if(solve(n-x, !turn, dp) == false){
                    return dp[n][turn] = true;
                }
            }
        }
        return dp[n][turn] = false;
    }

    bool divisorGame(int n) {
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve(n, 1, dp);
    }
};