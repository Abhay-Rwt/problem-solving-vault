class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> dp;
        for(int i=0; i<n; i++){
            vector<int> temp(i+1);
            for(int j=0; j<=i; j++){
                if(j == 0 || j == i){
                    temp[j] = 1;
                }
                else{
                    temp[j] = dp[i-1][j-1] + dp[i-1][j];
                }
            }
            dp.push_back(temp);
        }
        return dp;
    }
};