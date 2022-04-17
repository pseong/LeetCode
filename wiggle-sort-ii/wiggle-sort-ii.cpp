class Solution {
public:
    int n;
    
    /*
    bool f(int i) {
        return (i*2+1)%(n|1);
    }*/
    
    void wiggleSort(vector<int>& nums) {
        n = nums.size();
        
        nth_element(nums.begin(), nums.begin() + n/2, nums.end());
        int mid = *(nums.begin()+n/2);
        int i, j, k;
        i = j = 0;
        k = n-1;
        while (j <= k) {
            if (nums[(1+2*(j)) % (n|1)] > mid) {
                swap(nums[(1+2*(j++)) % (n|1)], nums[(1+2*(i++)) % (n|1)]);
            }
            else if (nums[(1+2*(j)) % (n|1)] < mid) {
                swap(nums[(1+2*(j)) % (n|1)], nums[(1+2*(k--)) % (n|1)]);
            }
            else {
                j++;
            }
        }
    }
};