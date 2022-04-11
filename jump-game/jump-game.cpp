class Solution {
public:
    bool dp[10101]{ 0 };
    bool canJump(vector<int>& nums) {
        dp[0] = 1;
        for (int i=0; i<nums.size(); i++) {
            if (dp[i] == 1) {
                for (int k=0; k<=nums[i]; k++) {
                    if (i+k >= nums.size()) break;
                    dp[i+k] = 1;
                }
            }
        }
        return dp[nums.size()-1];
    }
};