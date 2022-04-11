class TicTacToe {
public:
    vector<int> rows;
    vector<int> cols;
    int dia;
    int antiDia;
    int n;
    
    TicTacToe(int n) {
        this->n = n;
        rows.assign(n, 0);
        cols.assign(n, 0);
        dia = 0;
        antiDia = 0;
    }
    
    int move(int row, int col, int player) {
        int p = (player == 1) ? 1 : -1;
        rows[row] += p;
        cols[col] += p;
        if (row == col) dia += p;
        if (col + row == n-1) antiDia += p;
        if (
            abs(rows[row]) == n ||
            abs(cols[col]) == n ||
            abs(dia) == n ||
            abs(antiDia) == n
        ) {
            return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */