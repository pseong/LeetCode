class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        int sz = strs.size();
        for (int i=0; i<sz; i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            m[str].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        for (auto at : m) {
            ans.push_back(at.second);
        }
        return ans;
    }
};