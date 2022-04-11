class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(intervals.begin(), intervals.end());
        for (int i=0; i<n; i++) {
            while (pq.size() && pq.top() <= intervals[i][0]) {
                pq.pop();
            }
            pq.push(intervals[i][1]);
            ans = max(ans, (int)pq.size());
        }
        return ans;
    }
};