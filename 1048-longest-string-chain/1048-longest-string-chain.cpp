class Solution {
public:
    static bool comp(string &s1, string &s2){
        return s1.size() < s2.size();
    }

    bool isPredecessor(string &word1, string &word2){
        int cnt=0;
        if(word1.size() != word2.size() + 1) return false;

        int i=0, j=0;
        while(i < word1.size()){
            if(word1[i] == word2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return ( i == word1.size() && j == word2.size() );
    }

    int lis(int i, int prev, int n, vector<string> &words, vector<vector<int>> &dp){
        if(i >= n) return 0;

        if(dp[i][prev] != -1) return dp[i][prev];

        if(prev == n || isPredecessor(words[i], words[prev])){
            return dp[i][prev] = max(1 + lis(i+1, i, n, words, dp), lis(i+1, prev, n, words, dp));
        }
        
        return dp[i][prev] = lis(i+1, prev, n, words, dp);
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        sort(words.begin(), words.end(), comp);

        return lis(0, n, n, words, dp);
    }
};