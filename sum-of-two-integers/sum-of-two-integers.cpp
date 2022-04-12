class Solution {
public:
    int getSum(int a, int b) {
        do {
            pair<int, int> tmp = {a&b, a^b};
            tie(b, a) = tmp;
            b &= ~(1<<31);
            b <<= 1;
        } while (b);
        return a;
    }
};