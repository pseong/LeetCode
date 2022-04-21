class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        for (int right = 1; right < nums.size()-1; right++) {
            for (int left = right; left >= 1; left--) {
                for (int i=left; i<=right; i++) {
                    int gain = nums[left-1] * nums[i] * nums[right+1];
                    int remaining = dp[left][i-1] + dp[i+1][right];
                    dp[left][right] = max(dp[left][right], gain + remaining);
                }
            }
        }
        return dp[1][dp.size()-2];
    }
};