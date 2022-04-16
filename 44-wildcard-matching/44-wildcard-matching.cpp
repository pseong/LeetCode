class Solution {
public:
    bool isMatch(string s, string p) {
        s = "#" + s;
        p = "#" + p;
        
        vector<vector<bool>> dp(p.size(), vector<bool>(s.size(), 0));
        
        dp[0][0] = 1;
        for (int i=1; i<p.size(); i++) {
            if (p[i] == '*') {
                for (int b=0; b<s.size(); b++) {
                    if (dp[i-1][b]) {
                        for (int y=b; y<s.size(); y++) {
                            dp[i][y] = 1;
                        }
                        break;
                    }
                }
            }
            else if (p[i] == '?') {
                for (int b=1; b<s.size(); b++) {
                    if (dp[i-1][b-1]) dp[i][b] = 1;
                }
            }
            else {
                for (int b=1; b<s.size(); b++) {
                    if (s[b] == p[i] && dp[i-1][b-1]) dp[i][b] = 1;
                }
            }
        }
        return dp[p.size()-1][s.size()-1];
    }
};