class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int l = 0;
        int r = n-1;
        while (l <= r) {
            if (l == r) return l;
            int mid = l + (r-l)/2;
            if (nums[mid] > nums[mid+1]) {
                r = mid;
            }
            else {
                l = mid+1;
            }
        }
        return -1;
    }
};