class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        i = 0
        j = len(nums) - 1
        while i < j:
            if nums[i] % 2 == 0:
                i = i + 1
            if nums[j] % 2 != 0:
                j = j - 1
            if nums[i] % 2 != 0 and nums[j] % 2 == 0:
                if i < j:
                    temp = nums[i]
                    nums[i] = nums[j]
                    nums[j] = temp
                    i = i + 1
                    j = j - 1
        return nums
