class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    vector<int> reset() {
        return nums;        
    }
    
    vector<int> shuffle() {
        vector<int> v(nums);
        for (int i=0; i<(int)v.size(); i++) {
            int pos = rand()%((int)v.size());
            swap(v[i], v[pos]);
        }
        return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */