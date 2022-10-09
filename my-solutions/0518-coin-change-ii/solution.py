class Solution:
    def __init__(self):
        self.cache = {}
        
    def calc_ways(self, amount, coins):
        if len(coins) <= 0:
            return 0
        if amount == 0:
            return 1
        elif(amount < coins[0]):
            return 0
        elif amount == coins[0]:
            return 1
        else:
            sum = 0
            for i in range(len(coins)):
                if (amount, i) in self.cache:
                    sum += self.cache[(amount, i)]
                else:
                    temp = self.calc_ways(amount - coins[i], coins[0:(i+1)])
                    # print(amount - coins[i], coins[0:(i+1)])
                    self.cache[(amount, i)] = temp
                    sum += temp

            return sum

    def change(self, amount: int, coins: List[int]) -> int:
        coins.sort()
        return self.calc_ways(amount, coins)
