class Solution {
public:
    vector<string> ans;
    vector<vector<char>> table{
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'},
    };
    
    void go(int idx, string& now, string& digits) {
        if (idx == digits.size()) {
            ans.push_back(now);
            return;
        }
        for (char c : table[digits[idx]-'2']) {
            now.push_back(c);
            go(idx+1, now, digits);
            now.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits == "") return ans;
        string str = "";
        go(0, str, digits);
        return ans;
    }
};