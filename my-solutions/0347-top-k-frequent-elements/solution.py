import math
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = [[] for i in range(10000)]
        map_freq = {}
        result = []
        for i in range(len(nums)):
            if nums[i] in map_freq:
                map_freq[nums[i]] += 1
            else:
                map_freq[nums[i]] = 1

        for key in map_freq.keys():
            count = map_freq[key]
            counts[count].append(key)
            
        # print(map_freq)
        # print(counts)
          
        i = 1
        while k > 0 and i < len(counts):
            if len(counts[len(counts) - i]) != 0:
                if k > len(counts[len(counts) - i]):
                    result.extend(counts[len(counts) - i])
                    k -= len(counts[len(counts) - i])
                else:
                    result.extend(counts[len(counts) - i][:k])
                    return result
            i += 1
            
        return result
            
