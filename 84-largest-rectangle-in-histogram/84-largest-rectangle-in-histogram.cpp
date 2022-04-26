class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<pair<int, int>> st;
        st.push({-1, 0});
        int ans = 0;
        int erase = 0;
        for (int i=0; i<heights.size(); i++) {
            int remove = 0;
            while (st.top().first != -1 && heights[st.top().first] > heights[i]) {
                int idx, cnt;
                tie(idx, cnt) = st.top(); st.pop();
                remove += cnt+1;
                ans = max(ans, heights[idx]*(i-st.top().first-1));
            }
            st.push({i, remove});
        }
        return ans;
    }
};