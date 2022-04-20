class Solution {
public:
    vector<string> ans;
    string s;
    string now;
    
    void go(int i, unordered_set<string>& st) {
        if (i == s.size()) {
            now.pop_back();
            ans.push_back(now);
            now.push_back(' ');
            return;
        }
        for (int j=i; j<s.size(); j++) {
            string sub = s.substr(i,j-i+1);
            if (st.find(sub) != st.end()) {
                now += sub + " ";
                go(j+1, st);
                now.erase(now.size()-sub.size()-1);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this->s = s;
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        go(0, st);
        return ans;
    }
};