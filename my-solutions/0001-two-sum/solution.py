class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        diff_idx = {}

        for i in range(len(nums)):
            if nums[i] in diff_idx:
                return [i, diff_idx[nums[i]]]
            else:
                diff_idx[target - nums[i]] = i
        return [-1, -1]

