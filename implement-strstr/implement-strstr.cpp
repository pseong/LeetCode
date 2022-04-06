class Solution {
public:
    int table[50505]{ 0 };
    void makeTable(string& s) {
        int j = 0;
        for (int i=1; i<s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = table[j-1];
            }
            if (s[i] == s[j]) {
                table[i] = ++j;
            }
        }
    }
    
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        makeTable(needle);
        int j = 0;
        for (int i=0; i<haystack.size(); i++) {
            while (j>0 && haystack[i] != needle[j]) {
                j = table[j-1];
            }
            if (haystack[i] == needle[j]) {
                if (j == needle.size()-1) {
                    return i-needle.size() + 1;
                }
                else {
                    j++;
                }
            }
        }
        return -1;
    }
};