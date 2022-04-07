class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<bool> chk((int)nums.size()+1);
        for (int i=0; i<(int)nums.size(); i++) {
            chk[nums[i]] = 1;
        }
        for (int i=0; i<=(int)nums.size(); i++) {
            if (chk[i] == 0) return i;
        }
        return -1;
    }
};