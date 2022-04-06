// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1;
        int hi = INT_MAX;
        int ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            bool b = isBadVersion(mid);
            if (b) {
                hi = mid - 1;
                ans = mid;
            }
            else {;
                lo = mid + 1;
            }
        }
        return ans;
    }
};