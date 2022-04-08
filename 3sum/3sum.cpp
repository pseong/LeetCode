class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i=0; i<(int)nums.size()-2; i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = (int)nums.size()-1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[j++], nums[k--]});
                    while (j < k && nums[j] == nums[j-1]) j++;
                }
                else if (sum > 0) {
                    k--;
                }
                else {
                    j++;
                }
            }
        }
        return ans;
    }
};