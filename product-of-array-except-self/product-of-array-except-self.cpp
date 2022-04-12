class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> l = nums;
        vector<int> r = nums;
        for (int i=1; i<n; i++) {
            l[i] = l[i] * l[i-1];
        }
        for (int i=n-2; i>=0; i--) {
            r[i] = r[i] * r[i+1];
        }
        vector<int> ans(n);
        for (int i=0; i<n; i++) {
            int res = 1;
            if (i>0) res *= l[i-1];
            if (i<n-1) res *= r[i+1];
            ans[i] = res;
        }
        return ans;
    }
};