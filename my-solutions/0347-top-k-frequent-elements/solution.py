class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        num_freq = Counter(nums)
        return heapq.nlargest(k, num_freq.keys(), key=num_freq.get)
