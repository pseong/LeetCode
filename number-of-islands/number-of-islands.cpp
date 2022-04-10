class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        int dy[] = {-1, 0, 0, 1};
        int dx[] = {0, -1, 1, 0};
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    queue<pair<int, int>> q;
                    grid[i][j] = '0';
                    q.push({i, j});
                    while (q.size()) {
                        int x, y;
                        tie(x, y) = q.front();
                        q.pop();
                        for (int d=0; d<4; d++) {
                            int X = x + dx[d];
                            int Y = y + dy[d];
                            if (X<0 || X>=n || Y<0 || Y>=m) continue;
                            if (grid[X][Y] == '1') {
                                grid[X][Y] = '0';
                                q.push({X, Y});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};