class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int val = 0;
        int ans = nums[0];
        for (int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
            if (val < m[nums[i]]) {
                val = m[nums[i]];
                ans = nums[i];
            }
        }
        return ans;
    }
};