class Solution {
public:
    int cnt1[1010]{0};
    int cnt2[1010]{0};
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for (int i=0; i<nums1.size(); i++) {
            cnt1[nums1[i]]++;
        }
        for (int i=0; i<nums2.size(); i++) {
            cnt2[nums2[i]]++;
        }
        for (int i=0; i<=1000; i++) {
            for (int j=0; j<min(cnt1[i], cnt2[i]); j++) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};