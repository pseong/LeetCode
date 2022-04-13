class Solution {
public:
    int cal(int x, int y, int n, int m, vector<vector<int>>& board) {
        int cnt = 0;
        for (int i=x-1; i<=x+1; i++) {
            for (int j=y-1; j<=y+1; j++) {
                if (i<0 || i>=n || j<0 || j>=m || (x==i&&y==j)) continue;
                if (board[i][j]) cnt++;
            }
        }
        return cnt;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int cnt = cal(i, j, n, m, board);
                if (board[i][j]) {
                    if (cnt == 2 || cnt == 3) ans[i][j] = 1;
                }
                else {
                    if (cnt == 3) ans[i][j] = 1;
                }
            }
        }
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                board[i][j] = ans[i][j];
            }
        }
    }
};