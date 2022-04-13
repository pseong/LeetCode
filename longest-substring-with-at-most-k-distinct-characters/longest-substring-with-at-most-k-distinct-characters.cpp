class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int l = 0;
        int cnt[256]{ 0 };
        int ans = 0;
        int distinct = 0;
        for (int r=0; r<s.size(); r++) {
            if (!cnt[s[r]]) distinct++;
            cnt[s[r]]++;
            while (distinct > k) {
                cnt[s[l]]--;
                if (!cnt[s[l]]) distinct--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};