class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        currMax, currMin = 1, 1
        res = max(nums)
        for i in range(len(nums)):
            if nums[i] == 0:
                currMin, currMax = 1, 1
                continue

            temp = currMax
            currMax = max(currMax * nums[i], currMin * nums[i], nums[i])
            currMin = min(temp * nums[i], currMin * nums[i], nums[i])
            res = max(res, currMax)
            
        return res
