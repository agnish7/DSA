class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        num_cache = {}
        for i in range(len(nums)):
            if nums[i] in num_cache:
                return [num_cache[nums[i]], i]
            else:
                num_cache[target - nums[i]] = i
        
        return [-1, -1]
