class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& l, vector<vector<int>> r) {
        vector<vector<int>> ans;
        int leftY=0, rightY=0, curY=0;
        int idxL=0, idxR=0;
        while (!(idxL == l.size() && idxR == r.size())) {
            if (idxR == r.size() || idxL != l.size() && (l[idxL][0] < r[idxR][0])) {
                if (l[idxL][1] < curY) {
                    int pre = curY;
                    curY = max(rightY, l[idxL][1]);
                    if (pre != curY) ans.push_back({l[idxL][0], curY});
                }
                else if (l[idxL][1] > curY) {
                    curY = l[idxL][1];
                    ans.push_back({l[idxL][0], curY});
                }
                leftY = l[idxL][1];
                idxL++;
            }
            else if (idxL == l.size() || idxR != r.size() && (l[idxL][0] > r[idxR][0])) {
                if (r[idxR][1] < curY) {
                    int pre = curY;
                    curY = max(leftY, r[idxR][1]);
                    if (pre != curY) ans.push_back({r[idxR][0], curY});
                }
                else if (r[idxR][1] > curY){
                    curY = r[idxR][1];
                    ans.push_back({r[idxR][0], curY});
                }
                rightY = r[idxR][1];
                idxR++;
            }
            else {
                int pre = curY;
                curY = max(l[idxL][1], r[idxR][1]);
                if (pre != curY) ans.push_back({l[idxL][0], curY});
                leftY = l[idxL][1];
                rightY = r[idxR][1];
                idxL++;
                idxR++;
            }
        }
        return ans;
    }
    
    vector<vector<int>> divide(vector<vector<int>>& b, int l, int r) {
        if (l==r) return {{b[l][0], b[l][2]}, {b[l][1], 0}};
        int mid = (l+r)/2;
        vector<vector<int>> left = divide(b, l, mid);
        vector<vector<int>> right = divide(b, mid+1, r);
        return merge(left, right);
    }
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        return divide(buildings, 0, buildings.size()-1);
    }
};