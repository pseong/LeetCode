class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int lm = 0;
        int rm = 0;
        int ans = 0;
        while (l <= r) {
            lm = max(lm, height[l]);
            rm = max(rm, height[r]);
            int h = min(lm, rm);
            if (height[l] < height[r]) {
                ans += max(0, h-height[l]);
                l++;
            }
            else {
                ans += max(0, h-height[r]);
                r--;
            }
        }
        return ans;
    }
};