class Solution {
public:
    int no_of_bits(int n){
        int bits=0;
        while(n > 0){
            bits += (n & 1);
            n = n >> 1;
        }
        return bits;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [this](const int &a, const int &b){
            int bitsA = no_of_bits(a);
            int bitsB = no_of_bits(b);
            if(bitsA < bitsB) return true;
            else if(bitsA == bitsB) return (a < b);
            return false;
        });
        return arr;
    }
};