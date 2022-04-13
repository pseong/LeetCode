class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(0);
        for (int i=0; i<n;) {
            if (nums[i]>=0 && nums[i]<=n) {
                if (nums[i] == nums[nums[i]]) i++;
                else swap(nums[i], nums[nums[i]]);
            }
            else nums[i] = 0;
            if (nums[i]==0 || nums[i]==i) i++;
        }
        for (int i=1; i<=n; i++) {
            if (nums[i] != i) return i;
        }
        return n+1;
    }
};