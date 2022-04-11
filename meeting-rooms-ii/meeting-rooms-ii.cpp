class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans = 0;
        multiset<int> ms;
        sort(intervals.begin(), intervals.end());
        for (int i=0; i<n; i++) {
            while (ms.size() && *ms.begin() <= intervals[i][0]) {
                ms.erase(ms.begin());
            }
            ms.insert(intervals[i][1]);
            ans = max(ans, (int)ms.size());
        }
        return ans;
    }
};