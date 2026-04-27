class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # Handle empty
        if not prices: 
            return 0

        # Iterate over the array, keeping track of the minimum price seen on a previous day
        # Calculate the max profit we could make by selling on day i. The max of the max-profits
        # made by selling on i = 0...n is the max profit we could ever make in this scenario.
        min_price = prices[0]
        max_profit = 0
        for price in prices:
            # Calculate the max profit we could make by selling today
            profit = price - min_price
            max_profit = max(profit, max_profit)
            # Update the min price seen so far
            min_price = min(price, min_price)

        return max_profit