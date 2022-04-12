class Solution {
public:
    int getSum(int a, int b) {
        int carry = a&b;
        int sum = a^b;
        
        while (carry) {
            carry &= ~(1<<31);
            carry <<= 1;
            int cry = carry;
            cry = sum&cry;
            sum ^= carry;
            carry = cry;
        }
        
        return sum;
    }
};