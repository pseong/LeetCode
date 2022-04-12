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
        
        int val = divisor;
        int e = -1;
        while (val >= HALF_INT_MIN && val + val >= dividend) {
            val += val;
            e += e;
        }
        
        int ans = 0;
        while (true) {
            if (val >= dividend) {
                dividend -= val;
                ans += e;
            }
            if (e == -1) break;
            val >>= 1;
            e >>= 1;
        }
        
        if (neg != 1) ans = -ans;
        return ans;
    }
};