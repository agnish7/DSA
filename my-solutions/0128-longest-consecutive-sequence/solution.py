class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        num_set = set(nums)
        max_seq = 0
        for num in nums:
            seq = 1
            if num - 1 not in num_set:
                while(num + 1 in num_set):
                    num += 1
                    seq += 1
                max_seq = max(max_seq, seq)

        return max_seq
