class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> hi;
    priority_queue<int> lo;
    
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (lo.empty()) lo.push(num);
        else {
            if (num > lo.top()) {
                hi.push(num);
                while (!(lo.size()==hi.size() || lo.size()==hi.size()+1)) {
                    lo.push(hi.top());
                    hi.pop();
                }
            }
            else {
                lo.push(num);
                while (!(lo.size()==hi.size() || lo.size()==hi.size()+1)) {
                    hi.push(lo.top());
                    lo.pop();
                }
            }
        }
    }
    
    double findMedian() {
        if (lo.empty()) return 0;
        if (lo.size() == hi.size()+1) return lo.top();
        return (lo.top() + hi.top()) / (double)2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */