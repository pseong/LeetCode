class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> dq;
    int capacity;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;
        dq.splice(dq.begin(), dq, mp.find(key)->second);
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if (it == mp.end()) {
            if (mp.size() == capacity) {
                mp.erase(dq.back().first);
                dq.pop_back();
            }
            dq.push_front({key, value});
            mp[key] = dq.begin();
        }
        else {
            dq.splice(dq.begin(), dq, it->second);
            it->second->second = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */