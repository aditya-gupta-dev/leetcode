class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        profit = 0 
        for i in range(0, len(prices)): 
            for j in range(i, len(prices)): 
                new_profit = prices[j] - prices[i]
            
                if profit < new_profit: 
                    profit = new_profit
                    print(new_profit, prices[i], prices[j])

        return profit

prices = [7,1,5,3,6,4]
prices = [7,6,4,3,1]

print(Solution().maxProfit(prices))
