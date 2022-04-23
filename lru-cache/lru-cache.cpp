class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> dq;
    int capacity;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            dq.splice(dq.begin(), dq, mp.find(key)->second);
            return mp[key]->second;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) == mp.end()) {
            if (dq.size() == capacity) {
                mp.erase(dq.back().first);
                dq.pop_back();
            }
            dq.push_front({key, value});
            mp[key] = dq.begin();
        }
        else {
            dq.erase(mp[key]);
            dq.push_front({key, value});
            mp[key] = dq.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */