class Solution:
    def numDecodings(self, s: str) -> int:
        dp = [0 for i in range(len(s)+1)]
        dp[len(s)] = 1
        dp[len(s) - 1] = 1 if s[len(s) - 1] != '0' else 0
        for i in range(len(s) - 2, -1, -1):
            if s[i] == '0':
                dp[i] = 0
            elif s[i] == '1':
                dp[i] = dp[i+1] + dp[i+2]
            elif s[i] == '2':
                dp[i] = dp[i+1] + dp[i+2] if s[i+1] in "0123456" else dp[i+1]
            else:
                dp[i] = dp[i+1]
        
        # print(dp)
        return dp[0]
