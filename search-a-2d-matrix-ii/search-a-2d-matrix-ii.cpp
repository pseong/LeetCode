class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        for (int i=0; i<n; i++) {
            int f = lower_bound(matrix[i].begin(), matrix[i].end(), target) - matrix[i].begin();
            if (f != matrix[0].size() && matrix[i][f] == target) return true;
        }
        return false;
    }
};