class Solution(object):
    def __init__(self):
        self.cache = {}
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        if len(nums) in self.cache:
            return self.cache[len(nums)]
        else:
            self.cache[len(nums)] = max(nums[0] + self.rob(nums[2:]), self.rob(nums[1:]))
            return self.cache[len(nums)]
