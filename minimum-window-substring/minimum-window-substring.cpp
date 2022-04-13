class Solution {
public:
    string minWindow(string s, string t) {
        int hist[58]{ 0 };
        int cnt = t.size();
        for (int i=0; i<t.size(); i++) {
            hist[t[i]-'A']++;
        }
        
        int l = 0;
        int ans_l = -1;
        int len = 1000000;
        for (int r=0; r<s.size(); r++) {
            hist[s[r]-'A']--;
            if (hist[s[r]-'A'] >= 0) cnt--;
            if (!cnt) {
                while (!cnt) {
                    hist[s[l]-'A']++;
                    if (hist[s[l]-'A'] > 0) {
                        cnt++;
                        if (len > r-l+1) {
                            ans_l = l;
                            len = r-l+1;
                        }
                    }
                    l++;
                }
            }
        }
        if (ans_l == -1) return "";
        return s.substr(ans_l, len);
    }
};