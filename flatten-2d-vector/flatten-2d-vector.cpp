class Vector2D {
public:
    vector<vector<int>> v;
    int i, j;
    Vector2D(vector<vector<int>>& vec) {
        v = vec;
        i = 0;
        j = -1;
    }
    
    int next() {
        j++;
        while (j >= v[i].size()) {
            i++;
            j = 0;
        }
        return v[i][j];
    }
    
    bool hasNext() {
        int a = i;
        int b = j;
        b++;
        while (a < v.size() && b >= v[a].size()) {
            a++;
            b = 0;
        }
        if (a >= v.size() || b >= v[a].size()) return false;
        return true;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */