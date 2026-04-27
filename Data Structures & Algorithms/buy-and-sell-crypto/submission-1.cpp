class Solution {
public:
    // Complexity:
    // Time: O(n)
    // We iterate once over the entire prices array (size n) and each iteration, we only perform
    // constant-time O(1) operations (subtraction, max, min).
    // 
    // Space: O(1)
    // Regardless of the size of the input array (size n) we only use three local variables
    // and do not create any additional arrays. So the function uses constant space O(1).
    int maxProfit(vector<int>& prices) {
        // Handle empty
        if (prices.empty()) return 0;

        // Let's iterate over the array of prices.
        // For every possible day i, we'll calculate the max profit we could have made
        // by selling today (day i). This means that we should have bought the stock
        // at the minimum price we've seen up to this point.
        //
        // So we'll track:
        // - the minimum price we've seen. We'll use this as our buy price.
        // - the maximum profit we could make by selling on days 0...i
        // At the end, we'll have the max profit we could make by selling on any day 0 <= i < n
        int min_price = prices[0];
        int max_profit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            // Calculate the max profit we could make by selling on day i, update max_profit
            int profit = prices[i] - min_price;
            max_profit = std::max(profit, max_profit);
            // Update the min price we've seen so far
            min_price = std::min(prices[i], min_price);
        }
        return max_profit;
    }
};
