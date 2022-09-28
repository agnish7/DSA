class Solution:
    def climbStairs(self, n: int) -> int:
        fib1 = 0
        fib2 = 1
        for i in range(n):
            fib3 = fib1 + fib2
            fib1 = fib2
            fib2 = fib3
            
        return fib3
