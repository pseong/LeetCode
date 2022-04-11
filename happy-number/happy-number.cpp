class Solution {
public:
    bool isHappy(int n) {
        bool chk[3000]{ 0 };
        while (n != 1) {
            int res = 0;
            int tmp = n;
            while (tmp) {
                res += (tmp%10) * (tmp%10);
                tmp /= 10;
            }
            if (chk[res]) return false;
            chk[res] = 1;
            n = res;
        }
        return true;
    }
};