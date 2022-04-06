class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX;
        int profit = 0;
        for (int i=0; i<(int)prices.size(); i++) {
            if (prices[i] < mn) {
                mn = prices[i];
            }
            else if (prices[i] - mn > profit) {
                profit = prices[i] - mn;
            }
        }
        return profit;
    }
};