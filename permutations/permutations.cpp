class Solution {
public:
    vector<vector<int>> ans;
    vector<int> nums;
    int n;
    
    void go(int idx, vector<int>& nums) {
        if (idx == n) {
            ans.push_back(nums);
            return;
        }
        for (int i=idx; i<n; i++) {
            swap(nums[idx], nums[i]);
            go(idx+1, nums);
            swap(nums[idx], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
        go(0, nums);
        return ans;
    }
};