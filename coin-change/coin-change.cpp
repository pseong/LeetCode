class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        int dp[10101]{ 0 };
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for (int i=1; i<=amount; i++) {
            for (int c : coins) {
                if (i-c < 0) continue;
                if (dp[i-c] == -1) continue;
                if (dp[i] == -1) dp[i] = dp[i-c]+1;
                else dp[i] = min(dp[i], dp[i-c]+1);
            }
        }
        return dp[amount];
    }
};