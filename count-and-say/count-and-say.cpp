class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = countAndSay(n-1);
        int sz = s.size();
        string ans = "";
        int begin = 0;
        int end = 1;
        while (begin < sz) {
            while (end < sz && s[end] == s[end-1]) end++;
            ans += to_string(end-begin);
            ans += s[begin];
            begin = end++;
        }
        return ans;
    }
};