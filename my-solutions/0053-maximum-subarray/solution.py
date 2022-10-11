import math
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # check all negative
        allnegative = True
        max_elem = -math.inf
        for i in range(len(nums)):
            allnegative = allnegative and nums[i] < 0
            max_elem = max(max_elem, nums[i])
        if allnegative == True:
            return max_elem
        sum = 0;
        max_sum = -1
        for i in range(len(nums)):
            sum = sum + nums[i]
            if sum < 0:
                sum = 0
            
            max_sum = max(sum, max_sum)
            
        return max_sum
