class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for(int i=0; i<n; i++){
            if(nums[i] == 0) result[i] = 0;
            else if(nums[i] < 0){
                int index = i - abs(nums[i]);
                while(index < 0) index = n - abs(index);
                result[i] = nums[index];
            }
            else{
                int index = (i + nums[i]) % n;
                result[i] = nums[index];
            }
        }
        return result;
    }
};