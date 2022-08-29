class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        hashmap = {}
        hashmap[nums[0]] = 0
        for i in range(1, len(nums)):
            if nums[i] in hashmap.keys():
                return True
            else:
                hashmap[nums[i]] = i
        return False
        
