class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for (int i=0; i<(int)s.size(); i++) {
            string str = s.substr(i, 2);
            if (str == "IV") {
                ans += 4;
                i++;
            }
            else if (str == "IX") {
                ans += 9;
                i++;
            }
            else if (str == "XL") {
                ans += 40;
                i++;
            }
            else if (str == "XC") {
                ans += 90;
                i++;
            }
            else if (str == "CD") {
                ans += 400;
                i++;
            }
            else if (str == "CM") {
                ans += 900;
                i++;
            }
            else {
                if (s[i] == 'I') ans += 1;
                else if (s[i] == 'V') ans += 5;
                else if (s[i] == 'X') ans += 10;
                else if (s[i] == 'L') ans += 50;
                else if (s[i] == 'C') ans += 100;
                else if (s[i] == 'D') ans += 500;
                else if (s[i] == 'M') ans += 1000;
            }
        }
        return ans;
    }
};