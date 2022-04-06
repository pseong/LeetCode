class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        int dp[1010]{ 0 };
        dp[1] = nums[1];
        for (int i=2; i<=n; i++) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[n];
    }
};