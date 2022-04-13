class Solution {
public:
    deque<int> q;
    
    void add(vector<int>& nums, int i, int k) {
        if (q.size() && q.front() == i-k) q.pop_front();
        while (q.size() && nums[q.back()] <= nums[i]) q.pop_back();
        q.push_back(i);
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        for (int i=0; i<k; i++) {
            add(nums, i, k);
        }
        vector<int> ans;
        ans.push_back(nums[q.front()]);
        for (int i=k; i<nums.size(); i++) {
            add(nums, i, k);
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};