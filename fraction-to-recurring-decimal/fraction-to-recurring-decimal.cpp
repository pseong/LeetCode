class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        long long num = numerator;
        long long den = denominator;
        
        int cnt = 0;
        if (num < 0) {
            cnt++;
            num = -num;
        }
        if (den < 0) {
            cnt++;
            den = -den;
        }
        string sign;
        if (cnt == 1) sign = "-";
        
        vector<string> fraction;
        unordered_map<int, int> chk;
        
        long long a = num / den;
        num -= a*den;
        
        while (num != 0) {
            if (chk[num]) {
                string ans = sign + to_string(a) + ".";
                for (int i=0; i<chk[num]; i++) {
                    ans += fraction[i];
                }
                ans += "(";
                for (int i=chk[num]; i<fraction.size(); i++) {
                    ans += fraction[i];
                }
                ans += ")";
                return ans;
            }
            chk[num] = fraction.size();
            num *= 10;
            long long b = num / den;
            fraction.push_back(to_string(b));
            num -= b*den;
            
        }
        string ans = sign + to_string(a);
        if (fraction.size()) {
            ans += ".";
            for (int i=0; i<fraction.size(); i++) {
                ans += fraction[i];
            }
        }
        return ans;
    }
};