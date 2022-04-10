class Solution {
public:
    vector<string> ans;
    int n;
    string s;
    
    void go(int idx, int open, int close) {
        if (idx == n*2) {
            ans.push_back(s);
            return;
        }
        if (open < n) {
            s.push_back('(');
            go(idx+1, open+1, close);
            s.pop_back();
        }
        if (close < open) {
            s.push_back(')');
            go(idx+1, open, close+1);
            s.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        this->n = n;
        go(0, 0, 0);
        return ans;
    }
};