class Solution {
private:
    bool f(int i, int n, long long &target, long long prod1, long long prod2, vector<int> &nums)
    {
        if(i == n){
            if(prod1 == target && prod2 == target) return true;
            return false;
        }

        bool np = false;
        if(prod2 * nums[i] <= target){
            np = f(i+1, n, target, prod1, prod2 * nums[i], nums);
        }
        bool p = false;
        if(prod1 * nums[i] <= target){
            p = f(i+1, n, target, prod1 * nums[i], prod2, nums);
        }
        return np || p;
    }

public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        long long sm = 0;
        for(int it: nums) sm += it;
        if(target == 1) return sm == 2;
        return f(0, nums.size(), target, 1, 1, nums);    
    }
};