class Solution {
public:
    int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        for(int k=i; k<=j; k++){
            int coins = nums[i-1]*nums[k]*nums[j+1] + solve(i, k-1, nums, dp) + solve(k+1, j, nums, dp);
            ans = max(ans, coins);
        }
        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        // return solve(1, n-2, nums, dp);
        for(int i=n-2; i>=1; i--){
            for(int j=1; j<=n-2; j++){
                if(i > j){
                    dp[i][j] = 0;
                }
                else{
                    for(int k=i; k<=j; k++){
                        int coins = nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                        dp[i][j] = max(dp[i][j], coins);
                    }
                }
            }
        }
        return dp[1][n-2];
    }
};