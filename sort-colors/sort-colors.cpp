class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p1 = 0;
        int p2 = nums.size()-1;
        int cur = 0;
        while (cur <= p2) {
            if (nums[cur] == 2) {
                swap(nums[cur], nums[p2]);
                p2--;
            }
            else if(nums[cur] == 0) {
                swap(nums[cur], nums[p1]);
                cur++;
                p1++;
            }
            else {
                cur++;
            }
        }
    }
};