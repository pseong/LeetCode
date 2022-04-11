class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int lo = n;
        while (l <= r) {
            int mid = l+(r-l)/2;
            if (nums[mid] >= target) {
                lo = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        if (lo==n || nums[lo] != target) return {-1, -1};
        
        l = 0;
        r = n-1;
        int hi = -1;
        while (l <= r) {
            int mid = l+(r-l)/2;
            if (nums[mid] > target) {
                hi = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        if (hi == -1) hi = n;
        return {lo, hi-1};
    }
};