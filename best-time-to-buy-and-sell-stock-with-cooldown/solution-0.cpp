class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if (prices.size() <= 1) {
            return 0;
        }

        if (prices.size() == 2) {
            return max(prices[1] - prices[0], 0);
        }

        vector<int> buy(prices.size(), INT_MIN);
        vector<int> sell(prices.size(), 0);

        buy[0] = -prices[0];
        buy[1] = max(buy[0], -prices[1]);
        sell[1] = max(0, prices[1] - prices[0]);

        for (int i = 2; i < prices.size(); ++i) {
            buy[i] = max(sell[i - 2] - prices[i], buy[i - 1]);
            sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);
        }

        return max(buy[prices.size() - 1], sell[prices.size() - 1]);

    }
};