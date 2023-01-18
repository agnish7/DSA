import heapq

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        maxheap = []
        for stone in stones:
            heapq.heappush(maxheap, -stone)
        
        while(len(maxheap) > 1):
            x = -heapq.heappop(maxheap)
            y = -heapq.heappop(maxheap)
            if x > y:
                heapq.heappush(maxheap, -(x-y))
            elif y < x:
                heapq.heappush(maxheap, -(y-x))
        
        return -maxheap[0] if len(maxheap) > 0 else 0
