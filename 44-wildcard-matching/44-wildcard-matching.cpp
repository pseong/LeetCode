class Solution {
public:
    bool isMatch(string s, string p) {
        int sIdx = 0;
        int pIdx = 0;
        int starIdx = -1;
        int stmpIdx = -1;
        while (sIdx < s.size()) {
            if (pIdx < p.size() && p[pIdx] == '?' || s[sIdx] == p[pIdx]) {
                sIdx++;
                pIdx++;
            }
            else if (pIdx < p.size() && p[pIdx] == '*') {
                starIdx = pIdx;
                stmpIdx = sIdx;
                ++pIdx;
            }
            else if (starIdx == -1) {
                return false;
            }
            else {
                pIdx = starIdx + 1;
                sIdx = ++stmpIdx;
            }
        }
        for (int i=pIdx; i<p.size(); i++) {
            if (p[i] != '*') return false;
        }
        return true;
    }
};