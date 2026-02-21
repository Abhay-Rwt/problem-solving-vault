class Solution {
public:
    int func(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(amount == 0){
            return 0;
        }
        if(ind < 0){
            return 1e8;
        }
        if(dp[ind][amount] != -1) {
            return dp[ind][amount];
        }

        int np = func(ind-1, amount, coins, dp);

        int p = 1e8;

        if(coins[ind] <= amount){
            p = 1 + func(ind, amount-coins[ind], coins, dp);
        }

        return dp[ind][amount] = min(np, p);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        int ans = func(n-1, amount, coins, dp);
        return ans == 1e8 ? -1 : ans;
    }
};