class Solution {
public:
    int maxPro(int day, int canBuy, int cap, int n, vector<int> &price, vector<vector<vector<int>>> &dp){
        if(day == n || cap == 0) return 0;

        if(dp[day][canBuy][cap] != -1) return dp[day][canBuy][cap];

        int maxi = INT_MIN;

        if(canBuy == 1){
            maxi = max(
                maxPro(day+1, canBuy, cap, n, price, dp),
                -price[day] + maxPro(day+1, !canBuy, cap, n, price, dp)
            );
        }
        else{
            maxi = max(
                maxPro(day+1, canBuy, cap, n, price, dp),
                price[day] + maxPro(day+1, !canBuy, cap-1, n, price, dp)
            );
        }

        return dp[day][canBuy][cap] = maxi;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        return maxPro(0, 1, 2, n, prices, dp);
    }
};