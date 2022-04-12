class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            pair<int, int> tmp = {a^b, a&b};
            tie(a, b) = tmp;
            b &= ~(1<<31);
            b <<= 1;
        }
        return a;
    }
};