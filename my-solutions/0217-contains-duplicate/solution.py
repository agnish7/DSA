class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        num_set = set()
        for i in range(len(nums)):
            if nums[i] in num_set:
                return True
            else:
                num_set.add(nums[i])
        
        return False
        
