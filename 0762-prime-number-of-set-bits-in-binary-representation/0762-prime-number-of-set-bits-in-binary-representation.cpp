class Solution {
public:
    int set_bits(int n){
        int cnt=0;
        while(n){
            cnt += (n & 1);
            n = n >> 1;
        }
        return cnt;
    }

    int countPrimeSetBits(int left, int right) {
        vector<bool> prime(1e6+1, 1);

        prime[0] = prime[1] = 0;

        for(int i=2; i*i<=1e6; i++){
            if(prime[i]){
                for(int j=i*i; j<=1e6; j+=i){
                    prime[j] = 0;
                }
            }
        }

        int cnt = 0;

        for(int i=left; i<=right; i++){
            int setBits = set_bits(i);
            
            if(prime[setBits]){
                cnt++;
            }
        }

        return cnt;
    }
};