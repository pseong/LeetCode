class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dx[]{0, 1, 0, -1};
        int dy[]{1, 0, -1, 0};
        int d = 0;
        
        vector<int> ans;
        vector<vector<bool>> chk(n, vector<bool>(m, 0));
        int x = 0;
        int y = 0;
        while (true) {
            ans.push_back(matrix[x][y]);
            chk[x][y] = true;
            int a = x+dx[d];
            int b = y+dy[d];
            if (a<0 || a>=n || b<0 || b>=m || chk[a][b]) {
                d = (d+1)%4;
                a = x+dx[d];
                b = y+dy[d];
                if (a<0 || a>=n || b<0 || b>=m || chk[a][b]) {
                    return ans;
                }
            }
            x = a;
            y = b;
        }
        return ans;
    }
};