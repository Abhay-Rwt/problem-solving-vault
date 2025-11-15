class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp;
        
        for(int i=0; i<=rowIndex; i++){
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

        return dp[rowIndex];
    }
};