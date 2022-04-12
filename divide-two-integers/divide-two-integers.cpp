class Solution {
public:
    int HALF_INT_MIN = -1073741824;
    vector<int> divs;
    vector<int> pows;
    
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
        while (val >= dividend) {
            divs.push_back(val);
            pows.push_back(e);
            if (val < HALF_INT_MIN) break;
            val += val;
            e += e;
        }
        
        int ans = 0;
        for (int i=divs.size()-1; i>=0; i--) {
            if (dividend <= divs[i]) {
                dividend -= divs[i];
                ans += pows[i];
            }
        }
        
        if (neg != 1) ans = -ans;
        return ans;
    }
};