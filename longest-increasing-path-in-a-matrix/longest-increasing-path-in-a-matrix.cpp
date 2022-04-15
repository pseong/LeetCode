class Solution {
public:
    int dx[4]{-1, 0, 0, 1};
    int dy[4]{0, -1, 1, 0};
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> adj(n*m, vector<int>());
        vector<int> ans(n*m, 0);
        vector<int> in(n*m, 0);
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int a = i*m+j;
                for (int d=0; d<4; d++) {
                    int x = i + dx[d];
                    int y = j + dy[d];
                    if (x<0 || x>=n || y<0 || y>=m) continue;
                    int b = x*m+y;
                    if (matrix[i][j] < matrix[x][y]) {
                        adj[a].push_back(b);
                        in[b]++;
                    }
                }
            }
        }
        
        queue<int> q;
        for (int i=0; i<n*m; i++) {
            if (!in[i]) q.push(i);
            ans[i] = 1;
        }
        
        int res = 1;
        while (q.size()) {
            int x = q.front(); q.pop();
            for (int y : adj[x]) {
                ans[y] = max(ans[y], ans[x]+1);
                res = max(res, ans[y]);
                in[y]--;
                if (!in[y]) q.push(y);
            }
        }
        
        return res;
    }
};