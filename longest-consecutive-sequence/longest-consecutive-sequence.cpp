class Solution {
public:
    int init = 2000000000;
    int longestConsecutive(vector<int>& nums) {
        map<int, bool> m;
        for (int i=0; i<nums.size(); i++) {
            m[nums[i]] = true;
        }
        int ans = 0;
        int res = 0;
        int prev = 2000000000;
        for (auto it=m.begin(); it!=m.end(); it++) {
            if (prev==init || prev+1==it->first) {
                res++;
            }
            else {
                ans = max(ans, res);
                res = 1;
                prev = init;
            }
            prev = it->first;
        }
        ans = max(ans, res);
        return ans;
    }
};