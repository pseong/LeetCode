class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        
        for (int i=1; i<=100; i++) {
            squares.push_back(i*i);
        }
        
        vector<int> ans(n+1, 10000);
        ans[0] = 0;
        for (int i=1; i<=n; i++) {
            for (int x : squares) {
                if (i-x < 0) break;
                ans[i] = min(ans[i], ans[i-x] + 1);
            }
        }
        
        return ans[n];
    }
};