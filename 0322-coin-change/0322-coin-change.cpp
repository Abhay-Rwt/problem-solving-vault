class Solution {
public:
    int minCoins(int index, int remAmount, vector<int> &coins, vector<vector<int>> &dp){
        if(index == 0){
            if(remAmount%coins[index] == 0){
                return (remAmount/coins[index]);
            }
            return 1e8;
        }

        if(dp[index][remAmount] != -1){
            return dp[index][remAmount];
        }

        int notpick = minCoins(index-1, remAmount, coins, dp);

        int pick = 1e8;
        if(remAmount >= coins[index]){ 
            pick = 1 + minCoins(index, remAmount-coins[index], coins, dp);
        }

        return dp[index][remAmount] = min(pick, notpick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1));
        // int result = minCoins(n-1, amount, coins, dp);
        // return result == 1e8 ? -1 : result;

        // ############################## TABULATION ######################################

        // for index==0
        for(int remAmount=0; remAmount<=amount; remAmount++){
            if(remAmount % coins[0] == 0){
                dp[0][remAmount] = remAmount / coins[0];
            }
            else{
                dp[0][remAmount] = 1e8;
            }
        }

        for(int index=1; index<n; index++){
            for(int remAmount=0; remAmount<=amount; remAmount++){
                int notpick = dp[index-1][remAmount];
                int pick = 1e8;
                if(remAmount >= coins[index]){
                    pick = 1 + dp[index][remAmount-coins[index]];
                }

                dp[index][remAmount] = min(notpick, pick);
            }
        }

        return dp[n-1][amount] == 1e8 ? -1 : dp[n-1][amount];
    }
};