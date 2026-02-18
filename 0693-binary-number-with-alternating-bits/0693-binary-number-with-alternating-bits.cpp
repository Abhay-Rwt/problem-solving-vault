class Solution {
public:
    bool hasAlternatingBits(int n) {
        // first check lsb is 0 or 1?
        int lsb = n & 1;
        n = n >> 1;
        lsb = !lsb;

        while(n > 0){
            int bit = n & 1;
            if(bit != lsb){
                return false;
            }
            n = n >> 1;
            lsb = !lsb;
        }

        return true;
    }
};