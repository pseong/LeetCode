class Solution {
public:
    vector<int> nums;
    int n;
    vector<int> v;
    vector<vector<int>> ans;
    
    void go(int idx) {
        if (idx == n) {
            ans.push_back(v);
            return;
        }
        go(idx+1);
        v.push_back(nums[idx]);
        go(idx+1);
        v.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
        go(0);
        return ans;
    }
};