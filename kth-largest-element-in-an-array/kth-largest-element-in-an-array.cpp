class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> ms;
        for (int i=0; i<nums.size(); i++) {
            ms.insert(nums[i]);
            if (ms.size() > k) ms.erase(ms.begin());
        }
        return *ms.begin();
    }
};