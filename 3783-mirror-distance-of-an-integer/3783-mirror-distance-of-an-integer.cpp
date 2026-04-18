class Solution {
public:
    int mirrorDistance(int n) {
        int tmp = n;
        string s="";
        while(n){
            s.push_back((n%10) + '0');
            n /= 10;
        }
        int rv = stoi(s);
        return abs(tmp-rv);
    }
};