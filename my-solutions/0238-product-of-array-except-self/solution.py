class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        right = copy.deepcopy(nums)
        for i in range(1, len(nums)):
            nums[i] = nums[i - 1] * nums[i]

        for i in range(len(right) - 2, -1, -1):
            right[i] = right[i] * right[i + 1]

        # print(nums)
        # print(right)

        answer = [1] * len(nums)

        for i in range(1, len(nums) - 1):
            answer[i] = right[i+1] * nums[i-1]
        
        answer[0] = right[1]
        answer[len(nums) - 1] = nums[len(nums) - 2]

        return answer


