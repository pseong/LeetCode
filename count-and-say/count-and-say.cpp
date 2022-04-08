class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = countAndSay(n-1);
        int sz = s.size();
        char cur = s[0];
        int cnt = 1;
        string ans = "";
        for (int i=1; i<sz; i++) {
            if (cur == s[i]) {
                cnt++;
                continue;
            }
            ans += to_string(cnt);
            ans.push_back(cur);
            cur = s[i];
            cnt = 1;
        }
        ans += to_string(cnt);
        ans.push_back(cur);
        return ans;
    }
};