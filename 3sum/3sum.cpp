class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i=0; i<(int)nums.size()-2; i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;
            int f = -nums[i];
            int j = i+1;
            int k = (int)nums.size()-1;
            while (j < k) {
                int sum = nums[j] + nums[k];
                if (sum == f) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    k--;
                    j++;
                    while (j < (int)nums.size() && nums[j] == nums[j-1]) j++;
                    while (k > i && nums[k] == nums[k+1]) k--;
                }
                else if (sum > f) {
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