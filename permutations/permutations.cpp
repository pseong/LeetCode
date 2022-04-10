class Solution {
public:
    unsigned int chk = 0;
    vector<vector<int>> ans;
    vector<int> nums;
    int n;
    
    void go(int idx, vector<int>& v) {
        if (idx == n) {
            ans.push_back(v);
            return;
        }
        for (int i=0; i<n; i++) {
            if (chk & 1<<i) continue;
            chk |= 1<<i;
            v.push_back(nums[i]);
            go(idx+1, v);
            chk &= ~(1<<i);
            v.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
        vector<int> v;
        go(0, v);
        return ans;
    }
};