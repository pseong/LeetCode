class Solution {
public:
    int uniquePaths(int m, int n) {
        swap(n, m);
        int dp[110][110]{ 0 };
        dp[1][1] = 1;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (dp[i][j]) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};