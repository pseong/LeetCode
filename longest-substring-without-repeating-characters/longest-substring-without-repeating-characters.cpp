class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        queue<char> q;
        bool chk[300]{ 0 };
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (chk[s[i]]) {
                while (true) {
                    char c = q.front();
                    q.pop();
                    chk[c] = false;
                    if (c == s[i]) break;
                }
            }
            chk[s[i]] = true;
            q.push(s[i]);
            ans = max(ans, (int)q.size());
        }
        return ans;
    }
};