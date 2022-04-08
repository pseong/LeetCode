class Solution {
public:
    string conv(int l, int r) {
        if (l == r) return to_string(l);
        return to_string(l) + "->" + to_string(r);
    }
    
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<string> ans;
        int prev = lower-1;
        for (int i=0; i<=n; i++) {
            int cur = (i < n) ? nums[i] : upper + 1;
            if (prev+1 <= cur-1) {
                ans.push_back(conv(prev+1, cur-1));
            }
            prev = cur;
        }
        return ans;
    }
};