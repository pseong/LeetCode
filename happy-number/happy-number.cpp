class Solution {
public:
    int cal(int n) {
        int res = 0;
        while (n) {
            res += (n%10) * (n%10);
            n /= 10;
        }
        return res;
    }
    
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = cal(slow);
            fast = cal(fast);
            fast = cal(fast);
        } while (slow != fast);
        if (slow == 1) return true;
        return false;
    }
};