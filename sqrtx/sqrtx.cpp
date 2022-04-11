class Solution {
public:
    int mySqrt(int x) {
        long long ans = 1;
        while (true) {
            if (ans*ans > x) return ans-1;
            ans++;
        }
    }
};