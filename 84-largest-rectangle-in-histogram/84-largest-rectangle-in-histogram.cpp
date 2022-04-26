class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(), -1);
        heights.push_back(0);
        stack<pair<int, int>> st;
        st.push({0, 0});
        int ans = 0;
        int erase = 0;
        for (int i=1; i<heights.size(); i++) {
            if (heights[st.top().first] <= heights[i]) {
                st.push({i, 0});
            }
            else {
                int remove = 0;
                while (heights[st.top().first] > heights[i]) {
                    int idx, cnt;
                    tie(idx, cnt) = st.top(); st.pop();
                    remove += cnt;
                    ans = max(ans, heights[idx]*(i-idx+cnt));
                    remove++;
                }
                st.push({i, remove});
            }
        }
        return ans;
    }
};