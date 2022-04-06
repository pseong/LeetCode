class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);
        int ans = -10000;
        for (int i=0; i<(int)nums.size(); i++) {
            if (nums[i] + dp[i] < nums[i]) {
                dp[i+1] = nums[i];
            }
            else {
                dp[i+1] = dp[i] + nums[i];
            }
            ans = max(ans, dp[i+1]);
        }
        return ans;
    }
};