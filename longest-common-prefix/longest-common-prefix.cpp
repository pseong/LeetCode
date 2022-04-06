class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        bool end = false;
        for (int idx=0; 1; idx++) {
            if (end) break;
            char see = 'S';
            for (int i=0; i<strs.size(); i++) {
                if (idx >= strs[i].size()) {
                    end = true;
                    break;
                }
                if (see == 'S') see = strs[i][idx];
                if (strs[i][idx] != see) {
                    end = true;
                    break;
                }
            }
            if (end) break;
            ans.push_back(strs[0][idx]);
        }
        return ans;
    }
};