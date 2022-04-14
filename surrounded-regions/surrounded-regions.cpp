class Solution {
public:
    vector<vector<char>> b;
    int n, m;
    int dx[4]{-1, 0, 0, 1};
    int dy[4]{0, -1, 1, 0};
    
    void bfs(vector<vector<char>>& b, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        b[i][j] = '#';
        while (q.size()) {
            tie(i, j) = q.front(); q.pop();
            for (int d=0; d<4; d++) {
                int x = i+dx[d];
                int y = j+dy[d];
                if (x<0 || x>=n || y<0 || y>=m) continue;
                if (b[x][y] == 'O') {
                    b[x][y] = '#';
                    q.push({x, y});
                }
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        vector<vector<char>>& b = board;
        n = b.size();
        m = b[0].size();
        for (int j=0; j<m; j++) {
            if (b[0][j] == 'O') {
                bfs(b, 0, j);
            }
            if (b[n-1][j] == 'O') {
                bfs(b, n-1, j);
            }
        }
        for (int i=0; i<n; i++) {
            if (b[i][0] == 'O') {
                bfs(b, i, 0);
            }
            if (b[i][m-1] == 'O') {
                bfs(b, i, m-1);
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (b[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (b[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};