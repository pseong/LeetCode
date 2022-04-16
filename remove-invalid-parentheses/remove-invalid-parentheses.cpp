class Solution {
public:
    string s;
    unordered_set<string> ans;
    string now;
    int remove;
    void go(int idx, int open, int close, int pass) {
        if (idx == s.size()) {
            if (open == close && s.size()-now.size() == remove) {
                ans.insert(now);
            }
            return;
        }
        if (s[idx] >= 'a' && s[idx] <= 'z') {
            now.push_back(s[idx]);
            go(idx+1, open, close, pass);
            now.pop_back();
            return;
        }
        if (pass+1 <= remove) go(idx+1, open, close, pass+1);
        now.push_back(s[idx]);
        if (s[idx] == '(') {
            go(idx+1, open+1, close, pass);
        }
        else if (s[idx] == ')' && open >= close+1) {
            go(idx+1, open, close+1, pass);
        }
        now.pop_back();
    }
    
    vector<string> removeInvalidParentheses(string s) {
        this->s = s;
        int open = 0;
        int close = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(') open++;
            else if (s[i] == ')') {
                close++;
                if (close > open) {
                    remove++;
                    close--;
                }
            }
        }
        remove += abs(open - close);
        go(0, 0, 0, 0);
        return vector<string>(ans.begin(), ans.end());
    }
};