class Solution {
public:
    bool chk(int l, int r, string& str) {
        int s = l;
        int e = r;
        while (s < e) {
            if (str[s] == str[e]) {
                s++;
                e--;
            }
            else return false;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for (int i=0; i<n; i++) {
            for (int j=0; j<=i; j++) {
                if (s[j] != s[i]) continue;
                if (chk(j, i, s) && ans.size() < i-j+1) {
                    ans = s.substr(j, i-j+1);
                    break;
                }
            }
        }
        return ans;
    }
};