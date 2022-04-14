class Solution {
public:
    vector<int> adj[5000];
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        unordered_map<string, int> m;
        for (int i=0; i<wordList.size(); i++) {
            m[wordList[i]] = i;
        }     
        if (m.find(endWord) == m.end()) return 0;
        int ans[5000]{ 0 };
        queue<int> q;
        ans[(int)wordList.size()-1] = 1;
        q.push((int)wordList.size()-1);
        while (q.size()) {
            int idx = q.front(); q.pop();
            string& s = wordList[idx];
            for (int i=0; i<s.size(); i++) {
                char tmp = s[i];
                for (char c='a'; c<='z'; c++) {
                    s[i] = c;
                    auto it = m.find(s);
                    if (it != m.end() && !ans[it->second]) {
                        if (it->second == m[endWord]) {
                            return ans[idx] + 1;
                        }
                        ans[it->second] = ans[idx] + 1;
                        q.push(it->second);
                    }
                }
                s[i] = tmp;
            }
        }
        return 0;
    }
};