class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
        int cnt = 0, n = happiness.size();
        long long ans = 0;
        for(int i=0; i<n; i++){
            if(k == 0) break;
            if(happiness[i] > 0){
                happiness[i] -= cnt;
                if(happiness[i] < 0) happiness[i] = 0;
            }
            ans += happiness[i];
            cnt++;
            k--;
        }
        return ans;
    }
};