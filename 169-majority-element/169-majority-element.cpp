class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int candidate;
        for (int n : nums) {
            if (cnt == 0) candidate = n;
            cnt += (candidate == n) ? 1 : -1;
        }
        return candidate;
    }
};