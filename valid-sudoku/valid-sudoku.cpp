#include <bits/stdc++.h>
using namespace std;
using ll=long long;

class Solution {
public:
    bool w[10][10], h[10][10], s[3][3][10];
    bool ans = false;
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j]-'0';
                if (w[i][num] || h[j][num] || s[i/3][j/3][num]) {
                    return false;
                }
                w[i][num] = 1;
                h[j][num] = 1;
                s[i/3][j/3][num] = 1;
            }
        }
        return true;
    }
};