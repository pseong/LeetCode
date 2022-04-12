class Solution {
public:
    int getSum(int a, int b) {

        
        do {
            pair<int, int> p = {a&b, a^b};
            tie(b, a) = p;
            b &= ~(1<<31);
            b <<= 1;
        } while (b);
        
        return a;
    }
};