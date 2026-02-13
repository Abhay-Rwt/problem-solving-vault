class Solution {
public:
    int solve(int i, int j, int rows, int cols, vector<vector<int>> &dp){
        if(i == rows || j == cols) return 0;

        if(i == rows-1 && j == cols-1){
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = solve(i, j+1, rows, cols, dp);

        int down = solve(i+1, j, rows, cols, dp);

        return dp[i][j] = right + down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0, 0, m, n, dp);
    }
};