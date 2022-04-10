class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> cnt;
        for (int i=0; i<nums.size(); i++) {
            cnt[nums[i]]++;
        }
        
        priority_queue<pair<int, int>> pq;
        for (auto at : cnt) {
            pq.push({at.second, at.first});
        }
        
        vector<int> ans;
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};