class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = lower_bound(nums, target);
        int hi = lower_bound(nums, target+1);
        if (lo==nums.size() || nums[lo] != target) return {-1, -1};
        return {lo, hi-1};
    }
    
    int lower_bound(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int ans = nums.size();
        while (l <= r) {
            int mid = l+(r-l)/2;
            if (nums[mid] >= target) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};