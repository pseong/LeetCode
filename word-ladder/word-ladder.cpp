class Solution {
public:
    vector<int> adj[5000];
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
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
                        if (st.find(s) != st.end()) {
                            st.erase(s);
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
        // 방문 가능한 노드를 해시셋에 저장하고
        // 중복 방문을 방지하기 위해 큐에 넣을 때마다 해시셋에서 지워주는 방법을 쓰면
        // 굳이 방문노드를 저장할 필요가 없다.
    }
};