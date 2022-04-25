class NumMatrix {
public:
    struct BIT {
        vector<vector<int>> tree;
        void update(int a, int b, int x) {
            int i = a;
            while (i < tree.size()) {
                int j = b;
                while (j < tree[0].size()) {
                    tree[i][j] += x;
                    j += j&-j;
                }
                i += i&-i;
            }
        }
        
        int query(int a, int b) {
            int ans = 0;
            int i = a;
            while (i > 0) {
                int j = b;
                while (j > 0) {
                    ans += tree[i][j];
                    j -= j&-j;
                }
                i -= i&-i;
            }
            return ans;
        }
    } fwt;
    
    vector<vector<int>> matrix;
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        int n = matrix.size();
        int m = matrix[0].size();
        fwt.tree.resize(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                fwt.update(i+1, j+1, matrix[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        fwt.update(row+1, col+1, val - matrix[row][col]);
        matrix[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = fwt.query(row2+1, col2+1);
        int m1 = fwt.query(row2+1, col1);
        int m2 = fwt.query(row1, col2+1);
        int p = fwt.query(row1, col1);
        return sum - m1 - m2 + p;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */