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
        string ans;
        if (cnt == 1) ans += "-";
        
        unordered_map<int, int> chk;
        
        long long a = num / den;
        num %= den;
        ans += to_string(a);
        if (num == 0) return ans;
        ans += ".";
        
        while (num != 0) {
            if (chk.find(num) != chk.end()) {
                ans.insert(ans.begin()+chk[num], '(');
                ans.push_back(')');
                return ans;
            }
            chk[num] = ans.size();
            num *= 10;
            long long b = num / den;
            num %= den;
            ans += to_string(b);
        }
        return ans;
    }
};