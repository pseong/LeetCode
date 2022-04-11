class Solution {
public:
    int dp[3000]{ 0 };
    int lengthOfLIS(vector<int>& nums) {
        int idx = 1;
        dp[0] = nums[0];
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] > dp[idx-1]) {
                dp[idx] = nums[i];
                idx++;
            }
            else {
                int f = lower_bound(dp, dp+idx, nums[i]) - dp;
                dp[f] = nums[i];
            }
        }
        return idx;
    }
};