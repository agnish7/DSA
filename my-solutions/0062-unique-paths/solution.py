class Solution:
    def __init__(self):
        self.cache = {}
    def uniquePaths(self, m: int, n: int) -> int:
        if m == 1 and n == 1:
            return 1
        elif m < 1:
            return 0
        elif n < 1:
            return 0
        else:
            if (m, n) in self.cache.keys():
                return self.cache[(m, n)]
            else:
                ways = self.uniquePaths(m - 1, n) + self.uniquePaths(m, n - 1)
                self.cache[(m, n)] = ways
                return ways
        
