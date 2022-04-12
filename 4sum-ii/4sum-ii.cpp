class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int, int> m;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                m[nums1[i]+nums2[j]]++;
            }
        }
        int ans = 0;
        for (int a : nums3) {
            for (int b : nums4) {
                if (m.find(-(a+b)) != m.end()) {
                    ans += m[-(a+b)];
                }
            }
        }
        return ans;
    }
};