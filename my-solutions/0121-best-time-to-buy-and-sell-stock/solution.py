class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        running_min = inf
        running_max = -inf
        for i in range(len(prices)):
            if prices[i] < running_min:
                running_min = prices[i]
            if prices[i] - running_min > running_max:
                running_max = prices[i] - running_min
        return running_max
            
        
