import math

class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        elif len(nums) == 1:
            return nums[0]
        elif len(nums) == 2:
            return max(nums[0], nums[1])
        else:
            m0 = nums[0]
            m1 = max(nums[0], nums[1])
            m2 = -math.inf
            for i in range(2, len(nums)):
                m2 = max(m1, nums[i] + m0)
                m0 = m1
                m1 = m2
            return m2
