class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count_nums = Counter(nums)
        reverse_dict ={}
        for key, value in count_nums.items():
            if value in reverse_dict:
                reverse_dict[value].append(key)
            else:
                reverse_dict[value] = [key]
                
        heap = list(reverse_dict.keys())
        heap = [-i for i in heap]
        heapq.heapify(heap)
        result = []

        while len(heap) > 0:
            key = -heap[0]
            heapq.heappop(heap)
            for e in reverse_dict[key]:
                result.append(e)
                k -= 1
                if k <= 0:
                    return result
        
