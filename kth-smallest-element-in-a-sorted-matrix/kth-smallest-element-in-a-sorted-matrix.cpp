class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        for (int i=0; i<n; i++) {
            pq.push({matrix[i][0], i, 0});
        }
        
        int ans = -1;
        while (k--) {
            int val, x, y;
            tie(val, x, y) = pq.top(); pq.pop();
            ans = val;
            if (y+1<n) pq.push({matrix[x][y+1], x, y+1});
        }
        return ans;
    }
};