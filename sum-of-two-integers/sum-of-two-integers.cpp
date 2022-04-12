class Solution {
public:
    int getSum(int a, int b) {
        int carry = a&b;
        int sum = a^b;
        
        while (carry) {
            carry &= ~(1<<31);
            carry <<= 1;
            pair<int, int> p = {sum&carry, sum^carry};
            tie(carry, sum) = p;
        }
        
        return sum;
    }
};