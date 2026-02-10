class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;

        for(int i=0; i<n; i++){
            unordered_map<int,int> odd;
            unordered_map<int,int> even;
            for(int j=i; j<n; j++){
                if(nums[j] & 1)
                {
                    odd[nums[j]]++;
                }
                else{
                    even[nums[j]]++;
                }

                if(odd.size() == even.size()){
                    int currLen = j-i+1;
                    maxLen = max(maxLen, currLen);
                }
            }
        }

        return maxLen;
    }
};

