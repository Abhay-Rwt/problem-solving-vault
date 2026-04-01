class Solution {
public:
    int dp[101];
    int solve(int index, int n, vector<int> &nums){
        if(index >= n){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }

        int notrob = 0 + solve(index+1, n, nums);
        int rob = nums[index] + solve(index+2, n, nums);

        return dp[index] = max(notrob, rob);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        memset(dp, -1, sizeof(dp));
        int ans1 = solve(0, n-1, nums);
        memset(dp, -1, sizeof(dp));
        int ans2 = solve(1, n, nums);

        return max(ans1, ans2);
    }
};