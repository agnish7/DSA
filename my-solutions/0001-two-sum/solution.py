class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        nums_set = {}

        for i in range(len(nums)):
            if nums[i] in nums_set:
                return [nums_set[nums[i]], i]
            else:
                nums_set[target - nums[i]] = i
        
        return [-1, -1]
