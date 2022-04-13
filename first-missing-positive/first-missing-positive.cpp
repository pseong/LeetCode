class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n+2, 0);
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]<=n && nums[i]>=1) ans[nums[i]] = 1;
        }
        for (int i=1; i<n+2; i++) {
            if (ans[i] == 0) return i;
        }
        return -1;
    }
};