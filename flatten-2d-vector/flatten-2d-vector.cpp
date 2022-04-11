class Vector2D {
public:
    vector<int> v;
    int idx;
    Vector2D(vector<vector<int>>& vec) {
        for(vector<int>& i : vec) {
            v.insert(v.end(), i.begin(), i.end());
        }
        idx = -1;
    }
    
    int next() {
        idx++;
        return v[idx];
    }
    
    bool hasNext() {
        if (idx+1 < v.size()) return true;
        return false;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */