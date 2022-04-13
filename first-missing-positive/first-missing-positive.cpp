class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n : nums) {
            m[n]++;
        }
        for (int i=1;;i++) {
            if (!m[i]) return i;
        }
    }
};