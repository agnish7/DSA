from math import sqrt

class Solution(object):
    steps_map = {}
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        if n == 1:
            return 1
        dp = {}
        
        dp[1] = 1
        dp[2] = 2
        
        dp[3] = 3
        for i in range(3, n+1):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[n]
        
