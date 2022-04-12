class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        
        vector<int> one;
        vector<int> two;
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                one.push_back(nums1[i] + nums2[j]);
            }
        }
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                two.push_back(nums3[i] + nums4[j]);
            }
        }
        
        sort(one.begin(), one.end());
        sort(two.begin(), two.end());
        
        int ans = 0;
        for (int i=0; i<one.size(); i++) {
            ans += upper_bound(two.begin(), two.end(), -one[i])
                - lower_bound(two.begin(), two.end(), -one[i]);
        }
        return ans;
    }
};