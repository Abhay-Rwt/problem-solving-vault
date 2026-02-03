class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p = -1, q = -1, r = -1;
        int i = 0;
        while(i+1 < nums.size() && nums[i] < nums[i+1]){
            p = i+1;
            i++;
        }
        while(i+1 < nums.size() && nums[i] > nums[i+1]){
            q = i+1;
            i++;
        }
        while(i+1 < nums.size() && nums[i] < nums[i+1]){
            r = i+1;
            i++;
        }
        if(p == -1 || q == -1 || r == -1 || r != nums.size()-1) return false;
        return true;
    }
};