class Solution {
public:
    vector<int> adj[5000];
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> m(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int cnt = 1;
        while (q.size()) {
            int n = q.size();
            for (int i=0; i<n; i++) {
                string s = q.front(); q.pop();
                for (int j=0; j<s.size(); j++) {
                    char tmp = s[j];
                    for (char c='a'; c<='z'; c++) {
                        s[j] = c;
                        if (m.find(s) != m.end()) {
                            m.erase(s);
                            if (s == endWord) return cnt + 1;
                            q.push(s);
                        }
                    }
                    s[j] = tmp;
                }
            }
            cnt++;
        }
        return 0;
    }
};