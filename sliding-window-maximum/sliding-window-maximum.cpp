class Solution {
public:
    int bucket[150]{ 0 };
    int table[20202]{ 0 };
    int sz = 150;
    int mx = 0;
    int BIAS = 10000;
    
    void add(int x) {
        bucket[x/sz]++;
        table[x]++;
        if (x > mx) mx = x;
    }
    
    void sub(int x) {
        bucket[x/sz]--;
        table[x]--;
        if (!table[x] && mx==x) {
            for (int i=x/sz; i>=0; i--) {
                if (bucket[i]) {
                    for (int j=(i+1)*sz-1; j>=i*sz; j--) {
                        if (table[j]) {
                            mx = j;
                            return;
                        }
                    }
                }
            }
        }
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        for (int i=0; i<k; i++) {
            add(nums[i]+BIAS);
        }
        
        vector<int> ans;
        ans.push_back(mx-BIAS);
        for (int i=k; i<nums.size(); i++) {
            add(nums[i]+BIAS);
            sub(nums[i-k]+BIAS);
            ans.push_back(mx-BIAS);
        }
        return ans;
    }
};