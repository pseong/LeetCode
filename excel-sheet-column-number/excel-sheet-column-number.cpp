class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        long long digit = 1;
        for (int i=columnTitle.size()-1; i>=0; i--) {
            ans += digit * (columnTitle[i]-'A'+1);
            digit *= 26;
        }
        return ans;
    }
};