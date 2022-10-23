class Solution:
    def findMin(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        elif len(nums) == 2:
            return nums[0] if nums[0] < nums[1] else nums[1]
        
        l, r = 0, len(nums) - 1
        
        if(nums[l] < nums[r]):
            return nums[l]
        
        while (l <= r):
            mid = (l+r) // 2
            if nums[mid] > nums[mid+1]:
                return nums[mid+1]
            elif nums[mid] < nums[l]:
                r = mid
            else:
                l = mid
        
