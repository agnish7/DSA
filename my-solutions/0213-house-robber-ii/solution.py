class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        if len(nums) == 1:
            return nums[0]

        dp1 = [0 for i in range(len(nums) + 1)]
        dp2 = [0 for i in range(len(nums) + 1)]

        dp1[len(nums) - 1] = 0
        dp1[len(nums)] = 0

        dp2[0] = 0
        dp2[1] = 0

        for i in range(len(nums) - 2, -1, -1):
            dp1[i] = max(nums[i] + dp1[i+2], dp1[i+1])

        for i in range(2, len(nums)+1):
            dp2[i] = max(nums[i-1] + dp2[i-2], dp2[i-1])

        return max(dp1[0], dp2[-1])

