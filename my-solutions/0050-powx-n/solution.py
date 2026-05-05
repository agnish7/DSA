class Solution:
    @lru_cache(None)
    def fastPow(self, x, n):
        print(x, n)
        if n == 1:
            return x
        elif n == 0:
            return 1
        elif n == -1:
            return 1 / x

        p = n // 2
        half = self.fastPow(x, p)
        print(half)

        if n % 2:
            return half * half * x
        else:
            return half * half


    def myPow(self, x: float, n: int) -> float:
        return self.fastPow(x, n)
