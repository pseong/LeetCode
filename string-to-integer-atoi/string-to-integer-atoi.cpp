class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int start = 0;
        int ret = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '-') {
                if (start == 0) {
                    sign = -1;
                    start = 1;
                }
                else break;
            }
            else if (s[i] == '+') {
                if (start == 0) {
                    start = 1;
                }
                else break;
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                start = 1;
                int sum = s[i]-'0';
                if (sign == 1) {
                    if (ret > INT_MAX/10 || ret == INT_MAX/10 && sum >= 7) {
                        return INT_MAX;
                    }
                }
                else {
                    if (ret > INT_MAX/10 || ret == INT_MAX/10 && sum >= 8) {
                        return INT_MIN;
                    }
                }
                ret = ret*10 + sum;
            }
            else if (s[i] == ' ') {
                if (start == 1) break;
                else continue;
            }
            else break;
        }
        return ret * sign;
    }
};