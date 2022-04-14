class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> chk(n, 0);
        int cnt = 0;
        for (int i=0; i<n; i++) {
            if (!chk[i]) {
                cnt++;
                chk[i] = 1;
                queue<int> q;
                q.push(i);
                while (q.size()) {
                    int x = q.front(); q.pop();
                    for (int y=0; y<n; y++) {
                        if (!chk[y] && isConnected[x][y]) {
                            chk[y] = 1;
                            q.push(y);
                        }
                    }
                }
            }
        }
        return cnt;
    }
};