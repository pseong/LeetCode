class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*
        k %= nums.size();
        if (k == 0) return;
        for (int i=0; i<nums.size()-1 && i <= nums.size()-k+i%k; i++) {
            swap(nums[i], nums[nums.size()-k+i%k]);
        }*/
        
        int n = nums.size();
        vector<int> nums2 = nums;
        for (int i=0; i<n; i++) {
            nums[i] = nums2[(i+(long long)n*k-k)%n];
        }
    }
};