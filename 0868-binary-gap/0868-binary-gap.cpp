class Solution {
public:
    int binaryGap(int n) {
        int maxDist = 0;
        int ones = 0;
        
        while(n > 0){
            if(n & 1){
                ones++;
                n = n >> 1;
                int cnt = 1;
                while((n > 0) && (n & 1) == 0){
                    n = n >> 1;
                    cnt++;
                }

                if(n & 1) ones++;

                if(ones > 1)
                maxDist = max(maxDist, cnt);
            }
            else{
                n = n >> 1;
            }
        }

        return maxDist;
    }
};