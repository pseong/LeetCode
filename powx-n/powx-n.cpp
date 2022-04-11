class Solution {
public:
    double myPow(double x, int n) {
        if (n == INT_MIN) {
            return 1/(myPow(x, INT_MAX)*x);
        }
        if (n < 0) return 1/myPow(x, -n);
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n&1) return myPow(x, n-1)*x;
        double d = myPow(x, n/2);
        return d*d;
    }
};