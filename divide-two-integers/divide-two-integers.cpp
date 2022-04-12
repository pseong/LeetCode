class Solution {
public:
    int HALF_INT_MIN = -1073741824;
    
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        int neg = 2;
        if (dividend > 0) {
            neg--;
            dividend = -dividend;
        }
        if (divisor > 0) {
            neg--;
            divisor = -divisor;
        }
        
        int ans = 0;
        while (divisor >= dividend) {
            int exp = -1;
            int val = divisor;
            while (val >= HALF_INT_MIN && val + val >= dividend) {
                val += val;
                exp += exp;
            }
            ans += exp;
            dividend -= val;
        }
        
        if (neg != 1) ans = -ans;
        return ans;
    }
};