class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        res = []
        num_ctr = Counter(nums)
        rev_map = defaultdict(list)
        for key, val in num_ctr.items():
            rev_map[val].append(key)

        freqs = sorted(list(rev_map.keys()), reverse = True)
        
        for freq in freqs:
            for val in rev_map[freq]:
                res.append(val)
                k -= 1
                if k <= 0:
                    return res
        return res

        
