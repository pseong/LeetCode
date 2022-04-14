class Solution {
public:
    vector<int> adj[5000];
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> m;
        for (int i=0; i<wordList.size(); i++) {
            m[wordList[i]] = i;
        }     
        int ans[5000]{ 0 };
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (q.size()) {
            int cnt;
            string s;
            tie(s, cnt) = q.front(); q.pop();
            for (int i=0; i<s.size(); i++) {
                char tmp = s[i];
                for (char c='a'; c<='z'; c++) {
                    s[i] = c;
                    auto it = m.find(s);
                    if (it != m.end() && !ans[it->second]) {
                        if (s == endWord) {
                            return cnt+1;
                        }
                        ans[it->second] = cnt + 1;
                        q.push({it->first, cnt+1});
                    }
                }
                s[i] = tmp;
            }
        }
        return 0;
    }
};