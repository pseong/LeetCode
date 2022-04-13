class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int a = 0;
        int b = 0;
        char oper = '+';
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (isdigit(s[i])) {
                b = b*10 + (s[i]-'0');
            }
            if (s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || i==n-1) {
                if (oper=='+' || oper=='-') {
                    ans += a;
                    a = (oper=='+') ? b : -b;
                }
                else if (oper=='/') {
                    a /= b;
                }
                else if (oper=='*') {
                    a *= b;
                }
                oper = s[i];
                b = 0;
            }
        }
        return ans+a;
    }
};