class Solution {
public:
    int dp[1001][1001];

    int minDeletions(int i, int j, string &s1, string &s2){
        if(i < 0 && j < 0){
            return 0;
        }
        if(i < 0){
            int sum=0;
            while(j >= 0){
                sum += s2[j--];
            }
            return sum;
        }
        if(j < 0){
            int sum=0;
            while(i >= 0){
                sum += s1[i--];
            }
            return sum;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s1[i] == s2[j]){
            return dp[i][j] = 0 + minDeletions(i-1, j-1, s1, s2);
        }

        return dp[i][j] = min(s1[i] + minDeletions(i-1, j, s1, s2), s2[j] 
        + minDeletions(i, j-1, s1, s2));
    }

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        memset(dp, -1, sizeof(dp));

        return minDeletions(n-1, m-1, s1, s2);
    }
};