class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for (int i=1; i<numRows; i++) {
            ans.push_back({});
            vector<int>& v = ans.back();
            v.push_back(1);
            vector<int>& pre = ans[i-1];
            for (int j=0; j<(int)pre.size()-1; j++) {
                v.push_back(pre[j]+pre[j+1]);
            }
            v.push_back(1);
        }
        return ans;
    }
};