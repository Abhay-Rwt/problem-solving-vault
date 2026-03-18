class Solution {
public:
    int dp[31][31];
    vector<int> prefix;

    int solve(int i, int j, int k, vector<int> &stones){
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;

        for(int cut=i; cut<j; cut+=(k-1)){
            ans = min(ans, solve(i, cut, k, stones)+solve(cut+1, j, k, stones));
        }

        if((j-i)%(k-1) == 0){
            ans += prefix[j] - (i-1 >= 0 ? prefix[i-1] : 0);
        }

        return dp[i][j] = ans;
    }

    int mergeStones(vector<int>& stones, int k) {
        int n=stones.size();
        if((n-1)%(k-1) != 0) return -1;

        prefix.resize(n, 0);
        memset(dp, -1, sizeof(dp));

        int sm=0;
        for(int i=0; i<n; i++){
            sm+=stones[i];
            prefix[i]=sm;
        }

        return solve(0, n-1, k, stones);    
    }
};