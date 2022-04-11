class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = matrix.size()-1;
        int j = 0;
        while (i>=0 && j<(int)matrix[0].size()) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) i--;
            else j++;
        }
        return false;
    }
};