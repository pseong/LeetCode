class Solution {
public:
    int n, m;
    vector<vector<char>> board;
    vector<vector<bool>> chk;
    string word;
    bool ans = false;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    
    void go(int i, int j, int idx) {
        if (board[i][j] == word[idx]) {
            if (idx == (int)word.size()-1) {
                ans = true;
                return;
            }
            chk[i][j] = 1;
            for (int d=0; d<4; d++) {
                int x = i+dx[d];
                int y = j+dy[d];
                if (x<0 || x>=n || y<0 || y>=m) continue;
                if (chk[x][y]) continue;
                go(x, y, idx+1);
            }
            chk[i][j] = 0;
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;
        this->n = board.size();
        this->m = board[0].size();
        chk.resize(n, vector<bool>(m, 0));
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (ans) break;
                go(i, j, 0);
            }
        }
        return ans;
    }
};