class RandomizedSet {
public:
    set<int> st;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        int sz = st.size();
        st.insert(val);
        if (sz == st.size()) return false;
        return true;
    }
    
    bool remove(int val) {
        int sz = st.size();
        st.erase(val);
        if (sz == st.size()) return false;
        return true;
    }
    
    int getRandom() {
        int cnt = rand() % st.size();
        auto it = st.begin();
        while (cnt--) it++;
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */