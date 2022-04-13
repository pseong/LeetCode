class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int i=0; i<nums.size(); i++) {
            st.insert(nums[i]);
        }
        
        int ans = 0;
        for (int i=0; i<nums.size(); i++) {
            if (st.find(nums[i]-1) == st.end()) {
                int res = 0;
                int start = nums[i];
                while (st.find(start) != st.end()) {
                    res++;
                    start++;
                }
                ans = max(ans, res);
            }
        }
        return ans;
    }
};