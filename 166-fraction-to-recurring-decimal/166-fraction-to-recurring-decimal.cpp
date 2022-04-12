class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        long long num = numerator;
        long long den = denominator;
        
        string ans;
        if (num<0 ^ den<0) ans += "-";
        
        num = labs(num);
        den = labs(den);
        
        ans += to_string(num/den);
        num %= den;
        if (num == 0) return ans;
        ans += ".";
        
        unordered_map<int, int> chk;
        while (num != 0) {
            if (chk.find(num) != chk.end()) {
                ans.insert(ans.begin()+chk[num], '(');
                ans.push_back(')');
                return ans;
            }
            chk[num] = ans.size();
            num *= 10;
            ans += to_string(num/den);
            num %= den;
        }
        return ans;
    }
};