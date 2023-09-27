class Solution:
    def findMin(self, nums: List[int]) -> int:

        l, r  = 0, len(nums) - 1
        size = r
        
        while(l <= r):
            if l == r:
                return nums[l]
            if nums[l] < nums[r]:
                return nums[l]
            mid = int((l + r)  / 2)
            if mid != 0 and mid != size and nums[mid] < nums[mid - 1] and nums[mid] < nums[mid + 1]:
                return nums[mid]
            elif mid != 0 and mid != size and nums[mid] > nums[mid - 1] and nums[mid] > nums[mid + 1]:
                return nums[mid + 1]
            elif nums[mid] < nums[l]:
                r = mid - 1
            else:
                l = mid + 1

        return 1000
        
