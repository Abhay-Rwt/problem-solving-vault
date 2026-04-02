class Solution {
public:
    vector<vector<int>> ans;

    void f(int index, vector<int> temp, vector<int> &nums, int &n){
        if(index == n){
            ans.push_back(temp);
            return;
        }

        f(index+1, temp, nums, n);

        temp.push_back(nums[index]);

        f(index+1, temp, nums, n);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        
        f(0, {}, nums, n);
        return ans;
    }
};