class Solution {
public:
    int trailingZeroes(int n) {
        int five = 0;
        int two = 0;
        for (int i=1; i<=n; i++) {
            int go = i;
            while (go%2 == 0) {
                go /= 2;
                two++;
            }
            while (go%5 == 0) {
                go /= 5;
                five++;
            }
        }
        return min(two, five);
    }
};