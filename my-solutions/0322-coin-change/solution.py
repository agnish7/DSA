import math

class Solution:
    
    def coinChange(self, coins: List[int], amount: int) -> int:
        
        lemma = [amount + 1] * (amount + 1)
        lemma[0] = 0
        
        for a in range(1, amount + 1):
            for c in coins:
                if a - c >= 0:
                    lemma[a] = min(lemma[a], 1 + lemma[a - c])
        
        return lemma[amount] if lemma[amount] != amount + 1 else -1
