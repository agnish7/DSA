class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dp = [False] * (len(s) + 1)
        dp[len(s)] = True
        for i in range(len(s) - 1, -1, -1):
            for j in range(len(wordDict)):
                if s[i:].startswith(wordDict[j]):
                    if i + len(wordDict[j]) > len(dp):
                        dp[i] = 0
                    else:
                        dp[i] = dp[i] or dp[i + len(wordDict[j])]
                        if dp[i]:
                            break
        
        return dp[0]
