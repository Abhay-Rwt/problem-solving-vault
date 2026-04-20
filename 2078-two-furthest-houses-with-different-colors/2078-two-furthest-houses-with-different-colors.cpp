class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        // unordered_map<int,int> isVisited;
        int maxi=0;

        for(int i=0; i<n; i++){
            int j=n-1;
            while(j >= i){
                if(colors[i] != colors[j]){
                    maxi = max(maxi, j-i);
                    break;
                }
                j--;
            }
        }
        return maxi;
    }
};