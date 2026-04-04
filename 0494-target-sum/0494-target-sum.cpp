class Solution {
public:
    // func(i, j) = no. of ways to achieve j by changing the expressions consedering [0...i] only
    int dp[21][1001];

    int countWays(int index, int currTarget, vector<int> &nums)
    {
        if(index < 0){
            return 0;
        }
        if(index == 0){
            if(currTarget+nums[0] == 0 && currTarget-nums[0] == 0){
                return 2;
            }
            else if(currTarget+nums[0] == 0 || currTarget-nums[0] == 0){
                return 1;
            }
            return 0;
        }

        int add = countWays(index-1, currTarget+nums[index], nums);

        int sub = countWays(index-1, currTarget-nums[index], nums);

        return add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return countWays(n-1, target, nums);
    }
};