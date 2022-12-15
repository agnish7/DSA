from collections import defaultdict



class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        def dictRetVal():
            return None
        num_dict = defaultdict(dictRetVal)
        for i in range(len(nums)):
            if num_dict[nums[i]] != None:
                return [i, num_dict[nums[i]]]
            else:
                num_dict[target - nums[i]] = i
        return [0, 0]
        
