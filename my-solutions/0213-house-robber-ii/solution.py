class Solution(object):
    def __init__(self):
        self.cache = {}
    def robber(self, nums, i , j):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        # recurrence relation: rob(1:n) = max(arr[0] + rob(2:n-1), rob(1:n))

        if i > j:
            return 0
        if i == j:
            return nums[i]
        if (i, j) in self.cache:
            return self.cache[(i, j)]
        else:
            res = -1
            if i == 0:
                res = max(nums[i] + self.robber(nums, i+2, j - 1), self.robber(nums, i+1, j))
            else:
                res = max(nums[i] + self.robber(nums, i+2, j), self.robber(nums, i+1, j))
            self.cache[(i,j)] = res
            return res

    def rob(self, nums):
        return self.robber(nums, 0, len(nums) - 1)
