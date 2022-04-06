class Solution {
public:
    int cnt[101010]{ 0 };
    int singleNumber(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            cnt[nums[i]+30000]++;
        }
        for (int i=0; i<=60000; i++) {
            if (cnt[i] == 1) return i-30000;
        }
        return -1;
    }
};