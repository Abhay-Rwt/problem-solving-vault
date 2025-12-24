class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sm=0;
        for(int it: apple) sm += it;
        sort(capacity.rbegin(), capacity.rend());
        int cnt=0;
        for(int it: capacity){
            sm -= it;
            cnt++;
            if(sm <= 0) return cnt;
        }
        return 0;
    }
};