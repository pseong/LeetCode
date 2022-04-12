/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int n;
    int findCelebrity(int n) {
        this->n = n;
        int candidate = 0;
        for (int i=1; i<n; i++) {
            if (knows(candidate, i)) {
                candidate = i;
            }
        }
        if (isCelebrity(candidate)) {
            return candidate;
        }
        return -1;
    }
    
    bool isCelebrity(int j) {
        for (int i=0; i<n; i++) {
            if (i == j) continue;
            if (!knows(i, j) || knows(j, i)) {
                return false;
            }
        }
        return true;
    }
};