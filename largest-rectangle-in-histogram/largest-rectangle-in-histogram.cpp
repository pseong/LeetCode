class Solution {
public:
    struct Lazyseg {
        struct Node {
            int val;
            int idx;
        };
        typedef Node _T;
        int n;
        vector<_T> S;
        _T(*op)(_T, _T);
        _T t;
        Lazyseg(const vector<int>& A, _T(*op)(_T, _T), int n, _T t) : op(op), n(n), t(t) {
            S.resize(4*n+10, {0, 0});
            init(A, 1, 1, n);
        }
        _T init(const vector<int>& A, int node, int s, int e) {
            if (s == e) return S[node] = {A[s], s};
            int mid = (s+e)/2;
            return S[node] = op(init(A, node*2, s, mid), init(A, node*2+1, mid+1, e));
        }
        _T query(int node, int s, int e, int l, int r) {
            if (e < l || r < s) return t;
            if (l <= s && e <= r) return S[node];
            int mid = (s+e)/2;
            return op(query(node*2, s, mid, l, r), query(node*2+1, mid+1, e, l, r));
        }
        _T query(int l, int r) {
            return query(1, 1, n, l, r);
        }
    };

    static Lazyseg::Node op(Lazyseg::Node a, Lazyseg::Node b) {
        if (a.val < b.val) return a;
        else return b;
    }
    
    int daq(vector<int>& heights, int l, int r, Lazyseg& seg) {
        if (r < l) return 0;
        if (l == r) return heights[l];
        int mid = seg.query(l, r).idx;
        int left = daq(heights, l, mid-1, seg);
        int right = daq(heights, mid+1, r, seg);
        return max({left, right, (r-l+1)*heights[mid]});
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        heights.insert(heights.begin(), 0);
        Lazyseg seg{heights, op, n, {100000, 100000}};
        return daq(heights, 1, n, seg);
    }
};