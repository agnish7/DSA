class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = [1] * len(nums)
        left = [1] * (len(nums) + 1)
        for i in range(1, len(left)):
            left[i] = nums[i-1] * left[i-1]
        # print(left)

        right = [1] * (len(nums) + 1)
        for i in range(len(right) - 2, -1, -1):
            right[i] = nums[i] * right[i+1]
        # print(right)

        for i in range(len(res)):
            res[i] = left[i] * right[i+1]

        return res
