class Solution {
public:
    int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k=i; k<=j; k++){
            int cost = cuts[j+1] - cuts[i-1] + solve(i, k-1, cuts, dp) + solve(k+1, j, cuts, dp);
            ans = min(ans, cost);
        }
        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int size = cuts.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));
        // return solve(1, size-2, cuts, dp);
        for(int i=size-2; i>=1; i--){
            for(int j=1; j<=size-2; j++){
                if(i > j){
                    dp[i][j] = 0;
                }
                else{
                    int ans = INT_MAX;
                    for(int k=i; k<=j; k++){
                        int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                        ans = min(ans, cost);
                    }
                    dp[i][j] = ans;
                }
            }
        }
        return dp[1][size-2];
    }
};