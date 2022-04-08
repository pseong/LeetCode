class Solution {
public:
    vector<string> ans;
    
    void conv(int l, int r) {
        if (r < l) return;
        else if (l == r) ans.push_back(to_string(l));
        else ans.push_back(to_string(l) + "->" + to_string(r));
    }
    
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        int idx = lower_bound(nums.begin(), nums.end(), lower) - nums.begin();
        if (idx >= n) {
            conv(lower, upper);
            return ans;
        }
        if (idx < n && nums[idx] > lower) {
            conv(lower, nums[idx]-1);
        }
        while (++idx < n) {
            if (nums[idx] > upper) break;
            conv(nums[idx-1]+1, nums[idx]-1);
        }
        if (idx >= n && nums[idx-1] < upper) {
            conv(nums[idx-1]+1, upper);
        }
        return ans;
    }
};