
class Solution {
public:
    double solve(double x, long long n){
        if(n == 0) return 1.0;
        double ans;
        if(n & 1){
            ans = x * solve(x, n-1);
        }
        else{
            ans = solve(x * x, n/2);
        }
        return ans;
    }

    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        long long N = n;
        if(n < 0) return 1/solve(x, -N);
        else return solve(x, N);
    }   
};