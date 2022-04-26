class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> st;
        st.push(-1);
        int ans = 0;
        int erase = 0;
        for (int i=0; i<heights.size(); i++) {
            int remove = 0;
            while (st.top() != -1 && heights[st.top()] > heights[i]) {
                int idx = st.top(); st.pop();
                ans = max(ans, heights[idx]*(i-st.top()-1));
            }
            st.push(i);
        }
        return ans;
    }
};