class Solution {
public:
    // func(i, j) = no. of ways to achieve j by changing the expressions consedering [0...i] only
    int dp[21][100001];

    // count no. of subsets sum equals to target
    int solve(int ind, vector<int> &nums, int target){
        if(ind == 0){
            if(target == 0 && nums[0] == 0) return 2;
            if(target == 0 || nums[0] == target) return 1;
            return 0;
        }

        if(dp[ind][target] != -1) return dp[ind][target];

        int notpick = solve(ind-1, nums, target);

        int pick = 0;
        if(target >= nums[ind]){
            pick = solve(ind-1, nums, target - nums[ind]);
        }

        return dp[ind][target] = notpick + pick;
    }
    

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        // return countWays(n-1, target, nums);

        int totalSum = 0;
        for(int &it: nums) totalSum += it;
        
        // positiveSum - negativeSum = target
        // positiveSum + negativeSum = totalSum
        // positiveSum = (target + totalSum) / 2
        // So, the subsets with sum equals to positiveSum is the answer then
         
        if(totalSum < abs(target) || (totalSum+target) % 2 != 0){
            return 0;
        }

        return solve(n-1, nums, (totalSum+target)/2);
    }
};