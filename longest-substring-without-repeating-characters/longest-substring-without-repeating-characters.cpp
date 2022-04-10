class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> v(256, -1);
        
        int ans = 0;
        int start = -1;
        for (int i=0; i<n; i++) {
            if (v[s[i]] > start) start = v[s[i]];
            v[s[i]] = i;
            ans = max(ans, i - start);
        }
        return ans;
    }
};