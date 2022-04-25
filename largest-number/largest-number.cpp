class Solution {
public:
    static bool comp(int a, int b) {
        string A = to_string(a) + to_string(b);
        string B = to_string(b) + to_string(a);
        return A>B;
    }
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        string ans;
        for (int i : nums) {
            ans += to_string(i);
        }
        bool zero = true;
        for (int i=0; i<nums.size(); i++) {
            if (ans[i] != '0') zero = false;
        }
        if (zero) return "0";
        else return ans;
    }
};