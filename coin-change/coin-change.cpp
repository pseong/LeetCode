class Solution {
public:
    const int max = 10001;
    int coinChange(vector<int>& coins, int amount) {
        int dp[10101]{ 0 };
        fill(dp, dp+10101, max);
        dp[0] = 0;
        for (int i=1; i<=amount; i++) {
            for (int c : coins) {
                if (i-c < 0) continue;
                dp[i] = min(dp[i], dp[i-c]+1);
            }
        }
        if (dp[amount] == max) return -1;
        else return dp[amount];
    }
};