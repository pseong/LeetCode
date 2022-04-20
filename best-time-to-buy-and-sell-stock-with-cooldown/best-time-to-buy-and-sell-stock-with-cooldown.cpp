class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int held = INT_MIN;
        int sold = INT_MIN;
        int reset = 0;
        for (int i=0; i<prices.size(); i++) {
            tuple<int, int, int> next = {
                max(held, reset-prices[i]),
                held+prices[i],
                max(sold, reset),
            };
            tie(held, sold, reset) = next;
        }
        return max(sold, reset);
    }
};