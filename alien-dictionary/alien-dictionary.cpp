class Solution {
public:    
    string alienOrder(vector<string>& words) {
        vector<vector<int>> adj(26, vector<int>());
        vector<int> in(26, 0);
        vector<bool> chk(26, 0);
        int n = words.size();
        
        for (int i=0; i<words.size(); i++) {
            for (int j=0; j<words[i].size(); j++) {
                chk[words[i][j]-'a'] = 1;
            }
        }
        
        for (int i=0; i<words.size(); i++) {
            for (int j=i+1; j<words.size(); j++) {
                int n = min(words[i].size(), words[j].size());
                int k=0;
                for (; k<n; k++) {
                    if (words[i][k] != words[j][k]) {
                        adj[words[i][k]-'a'].push_back(words[j][k]-'a');
                        in[words[j][k]-'a']++;
                        break;
                    }
                }
                if (k == n) {
                    if (words[i].size() > words[j].size()) return "";
                }
            }
        }
        queue<int> q;
        string ans;
        for (int i=0; i<26; i++) {
            if (chk[i] && !in[i]) {
                q.push(i);
                ans.push_back('a'+i);
            }
        }
        
        while (q.size()) {
            int x = q.front(); q.pop();
            for (int y : adj[x]) {
                in[y]--;
                if (!in[y]) {
                    q.push(y);
                    ans.push_back('a'+y);
                }
            }
        }
        
        int cnt = 0;
        for (int i=0; i<26; i++) {
            if (chk[i]) cnt++;
        }
        
        if (cnt == ans.size()) {
            return ans;
        }
        else return "";
    }
};