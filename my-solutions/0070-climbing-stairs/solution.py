class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 0 or n == 1:
            return 1
        else:
            n0 = 1
            n1 = 1
            n2 = -1
            for i in range(2, n+1):
                n2 = n1 + n0
                n0 = n1
                n1 = n2
            return n2
