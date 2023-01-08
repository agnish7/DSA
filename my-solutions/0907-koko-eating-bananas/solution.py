from math import ceil

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def calc(piles, k):
            times = [math.ceil(piles[i] / k) for i in range(len(piles))]
            return sum(times)
        if len(piles) == 1:
            return calc(piles, h)
        
        
        piles.sort()
        # print(piles)
        # print(calc(piles, 14))
        low, high = 1, piles[-1]
        while(low <= high):
            mid = (low + high) // 2
            # print(low, mid, high, calc(piles, mid), calc(piles, mid - 1), h)
            if calc(piles, mid) <= h and calc(piles, mid - 1) > h:
                break
            elif calc(piles, mid) == h and calc(piles, mid - 1) == h:
                high = mid - 1
            elif calc(piles, mid) < h:
                high = mid - 1
            else:
                low = mid + 1
        
        return mid

