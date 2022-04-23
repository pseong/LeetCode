/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> v;
    int idx = 0;
    
    void get(vector<NestedInteger>& ni) {
        for (int i=0; i<ni.size(); i++) {
            if (ni[i].isInteger()) v.push_back(ni[i].getInteger());
            else {
                get(ni[i].getList());
            }
        }
    }
    
    NestedIterator(vector<NestedInteger>& nestedList) {
        get(nestedList);
    }
    
    int next() {
        return v[idx++];
    }
    
    bool hasNext() {
        return idx < v.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */