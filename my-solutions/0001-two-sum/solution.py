class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_map = {}
        for i in range(len(nums)):
            if nums[i] in num_map:
                return [i, num_map[nums[i]]]
            else:
                num_map[target - nums[i]] = i
        return [0, 0]
