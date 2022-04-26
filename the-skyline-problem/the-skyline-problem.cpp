class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> v;
        for (vector<int>& wall : buildings) {
            v.push_back({wall[0], -wall[2]});
            v.push_back({wall[1], wall[2]});
        }
        sort(v.begin(), v.end());
        multiset<int> ms;
        vector<vector<int>> ans;
        for (vector<int>& wall : v) {
            if (wall[1] < 0) {
                ms.insert(-wall[1]);
            }
            else {
                ms.erase(ms.find(wall[1]));
            }
            if (ms.size() && (!ans.size() || ans.size() && ans.back()[1] != *ms.rbegin())) {
                ans.push_back({wall[0], *ms.rbegin()});
            }
            else if (!ms.size()) ans.push_back({wall[0], 0});
        }
        return ans;
    }
};