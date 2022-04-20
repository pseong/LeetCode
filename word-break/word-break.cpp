class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size(), 0);
        for (int i=0; i<s.size(); i++) {
            if (i!=0 && !dp[i-1]) continue;
            for (int j=i; j<s.size(); j++) {
                if (st.find(s.substr(i, j-i+1)) != st.end()) dp[j] = 1;
            }
        }
        return dp[s.size()-1];
    }
};