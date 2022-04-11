class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (divisor == 1) return dividend;
        else if (divisor == -1) return -dividend;
        return (long long)dividend / divisor;
    }
};