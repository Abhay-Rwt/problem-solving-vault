class Solution {
public:
    bool solve(int index, int sum, vector<int>& nums, int target, vector<vector<int>> &dp){
        if(index < 0 || sum > target){
            return false;
        }
        if(index == 0){
            if(sum == target || sum + nums[0] == target){
                return true;
            }
            return false;
        }
        if(dp[index][sum] != -1){
            return dp[index][sum];
        }

        bool notpick = solve(index-1, sum, nums, target, dp);
        
        bool pick = solve(index-1, sum+nums[index], nums, target, dp);

        return dp[index][sum] = ( notpick || pick );
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int &it:nums) sum += it;
        if(sum & 1) return false;
        vector<vector<int>> dp(n, vector<int>((sum/2)+1, -1));
        return solve(n-1, 0, nums, sum/2, dp);
    }
};