class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        int lo = -1;
        int hi = -1;
        for (int i=0; i<n; i++) {
            if (lo == -1) {
                lo = intervals[i][0];
                hi = intervals[i][1];
                continue;
            }
            if (hi >= intervals[i][0]) {
                hi = max(hi, intervals[i][1]);
                continue;
            }
            ans.push_back({lo, hi});
            lo = intervals[i][0];
            hi = intervals[i][1];
        }
        ans.push_back({lo, hi});
        return ans;
    }
};