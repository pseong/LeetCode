class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end());
        vector<vector<int>> ans(people.size(), vector<int>(2, -1));
        for (int i=0; i<people.size(); i++) {
            int cnt = 0;
            for (int j=0; j<people.size(); j++) {
                if (ans[j][0] == -1 || ans[j][0] == people[i][0]) {
                    if (cnt == people[i][1]) {
                        ans[j] = people[i];
                        break;
                    }
                    cnt++;
                }
            }
        }
        return ans;
    }
};