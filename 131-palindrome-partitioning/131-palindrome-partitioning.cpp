class Solution {
public:
    vector<vector<string>> ans;
    vector<string> now;
    void go(int idx, string& s, vector<vector<bool>>& pal) {
        if (idx == s.size()) {
            ans.push_back(now);
            return;
        }
        for (int i=idx; i<s.size(); i++) {
            if (pal[idx][i]) {
                now.push_back(s.substr(idx, i-idx+1));
                go(i+1, s, pal);
                now.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> pal(s.size(), vector<bool>(s.size(), 0));
        for (int i=0; i<s.size(); i++) {
            for (int k=0; k<s.size(); k++) {
                int a = i-k;
                int b = i+k;
                if (a<0 || b >=s.size()) break;
                if (s[a] == s[b]) pal[a][b] = 1;
                else break;
            }
        }
        for (int i=0; i<s.size(); i++) {
            for (int k=0; k<s.size(); k++) {
                int a = i-k;
                int b = i+1+k;
                if (a<0 || b >=s.size()) break;
                if (s[a] == s[b]) pal[a][b] = 1;
                else break;
            }
        }
        go(0, s, pal);
        return ans;
    }
};