class Solution {
public:
    struct Seg {
        int tree[100000]{ 0 };
        
        void update(int n, int s, int e, int x) {
            if (x<s || e<x) return;
            if (s == e) {
                tree[n]++;
                return;
            }
            int mid = (s+e)/2;
            update(n*2, s, mid, x);
            update(n*2+1, mid+1, e, x);
            tree[n] = tree[n*2] + tree[n*2+1];
        }
        
        int query(int n, int s, int e, int l, int r) {
            if (r<l) return 0;
            if (r<s || e<l) return 0;
            if (l<=s && e<=r) return tree[n];
            int mid = (s+e)/2;
            return query(n*2, s, mid, l, r) + query(n*2+1, mid+1, e, l, r);
        }
    } seg;
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        for (int i=nums.size()-1; i>=0; i--) {
            int k = nums[i] + 10001;
            ans[i] = seg.query(1, 1, 20001, 1, k-1);
            seg.update(1, 1, 20001, k);
        }
        return ans;
    }
};