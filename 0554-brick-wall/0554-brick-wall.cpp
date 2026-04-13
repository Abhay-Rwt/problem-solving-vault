class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        // 1 3 5 6
        // 3 4 6
        // 1 4 6
        // 2 6
        // 3 4 6
        // 1 4 5 6

        int n = wall.size();

        unordered_map<int,long long> freq;

        for(int i=0; i<n; i++){
            int m = wall[i].size()-1;
            long long sum=0;
            for(int j=0; j<m; j++){
                sum+=wall[i][j];
                freq[sum]++;
            }
        }

        long long maxFreq = 0;
        for(auto &it: freq){
            maxFreq = max(maxFreq, it.second);
        }

        return n - maxFreq;
    }
};