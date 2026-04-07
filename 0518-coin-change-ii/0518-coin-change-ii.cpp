#define ll long long

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<ll>> dp(n, vector<ll>(amount+1));
        
        for(int remAmount=0; remAmount<=amount; remAmount++){
            if(remAmount % coins[0] == 0){
                dp[0][remAmount] = 1;
            }
            else{
                dp[0][remAmount] = 0;
            }
        }

        for(int index=1; index<n; index++){
            for(int remAmount=0; remAmount<=amount; remAmount++){
                int notpick = dp[index-1][remAmount];
                int pick = 0;
                if(remAmount >= coins[index]){
                    pick = dp[index][remAmount-coins[index]];
                }

                dp[index][remAmount] = 1LL*notpick + 1LL*pick;
            }
        }

        return dp[n-1][amount];
    }
};