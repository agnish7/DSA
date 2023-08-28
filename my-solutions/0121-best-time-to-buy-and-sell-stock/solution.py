class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxProfit, minPrice = float(-inf), float(inf)
        for i in range(len(prices)):
            maxProfit = max(prices[i] - minPrice, maxProfit)
            minPrice = min(minPrice, prices[i])
        
        return maxProfit if maxProfit > 0 else 0
