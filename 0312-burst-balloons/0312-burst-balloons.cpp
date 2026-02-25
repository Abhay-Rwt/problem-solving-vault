class Solution {
public:
    int dp[301][301];

    int maxCoins(int i, int j, vector<int> &nums){
        if(i > j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int mx=0;
        for(int k=i; k<=j; k++){
            int coins = maxCoins(i, k-1, nums) + maxCoins(k+1, j, nums) 
            + (nums[i-1] * nums[j+1] * nums[k]);

            mx = max(mx, coins);
        }

        return dp[i][j] = mx;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();

        memset(dp, -1, sizeof(dp));

        return maxCoins(1, n-2, nums);
    }
};