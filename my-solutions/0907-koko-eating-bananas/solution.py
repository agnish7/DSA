class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def pile_eat_time(pile_size, rate):
            if pile_size % rate == 0:
                return int(pile_size / rate)
            else:
                return pile_size // rate + 1

        def total_eat_time(piles, k):
            eat_times = [pile_eat_time(pile, k) for pile in piles]
            return sum(eat_times)

        l = 1
        r = max(piles)
        res = float('inf')
        while(l <= r):
            mid = (l + r) // 2
            print(mid, total_eat_time(piles, mid))
            if total_eat_time(piles, mid) <= h:
                res = min(res, mid)
                r = mid - 1
            else:
                l = mid + 1        
        return res
