class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        
        set_nums = set(nums)
        
        max_seq = 1
        
        for i in range(len(nums)):
            curr_max = 1
            if (nums[i] - 1) not in set_nums:
                j = 1
                while (nums[i] + j) in set_nums:
                    curr_max += 1
                    j += 1
                max_seq = curr_max if curr_max > max_seq else max_seq
        
        return max_seq
                
