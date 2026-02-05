class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n-1;
        int ans = -1;

        while(low <= high){
            int mid = (low + high) / 2;
            int cnt = 0;
            for(int i=0; i<n; i++) cnt += (nums[i] <= mid);

            if(cnt <= mid){
                low = mid+1;
            }
            else{
                ans = mid;
                high = mid-1;
            }
        }

        return ans;
    }
};