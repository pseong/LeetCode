class Solution {
public:    
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        int l = 0;
        int r = 0;
        for (int i=0; i<n; i++) {
            dp[i][i] = true;
        }
        for (int i=0; i<n-1; i++) {
            if (s[i] == s[i+1]) {
                l = i;
                r = i+1;
                dp[i][i+1] = true;
            }
        }
    
        for (int k=3; k<=n; k++) {
            for (int i=0; i<n-k+1; i++) {
                if (dp[i+1][i+k-2] && s[i] == s[i+k-1]) {
                    dp[i][i+k-1] = true;
                    if (k > l-r+1) {
                        l = i;
                        r = i+k-1;
                    }
                }
            }
        }
        return s.substr(l, r-l+1);
    }
};