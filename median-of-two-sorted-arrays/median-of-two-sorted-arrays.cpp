class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        int k = n/2+1;
        int lo = -1000000;
        int hi = 1000000;
        int ans;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            int right = nums1.end() - lower_bound(nums1.begin(), nums1.end(), mid);
            right += nums2.end() - lower_bound(nums2.begin(), nums2.end(), mid);
            if (right >= (n+1)/2) {
                ans = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        lo = -100000;
        hi = 100000;
        int ans2;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            int right = nums1.end() - lower_bound(nums1.begin(), nums1.end(), mid);
            right += nums2.end() - lower_bound(nums2.begin(), nums2.end(), mid);
            if (right >= (n+1)/2+1) {
                ans2 = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        if (n%2 == 0) {
            return ((ans+ans2)/(double)2);
        }
        else return ans;
    }
};