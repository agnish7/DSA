class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if(len(nums) == 0):
            return 0
        num_set = set(nums)
        max_len = 1
        for num in nums:
            curr_len = 0
            if num + 1 in num_set:
                continue
            elif (num - 1 in num_set):
                temp = num
                while(temp in num_set):
                    temp = temp - 1
                    curr_len += 1
            max_len = max(curr_len, max_len)
        return max_len
