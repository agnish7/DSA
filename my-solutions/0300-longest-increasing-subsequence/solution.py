class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = [1] * len(nums)
        
        for i in range(len(nums)):
            maximum = -1
            for j in range(i-1, -1, -1):
                if nums[i] > nums[j]:
                    maximum = 1 + dp[j] if 1 + dp[j] > maximum else maximum
            dp[i] = maximum if maximum != -1 else dp[i]
        
        return max(dp)


