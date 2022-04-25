class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<int, unordered_map<int, int>> mp;
        int ans = 1;
        for (int i=0; i<points.size(); i++) {
            mp.clear();
            for (int j=i+1; j<points.size(); j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int gcd = __gcd(dx, dy);
                dx /= gcd;
                dy /= gcd;
                ans = max(ans, ++mp[dx][dy]+1);
            }
        }
        return ans;
    }
};