class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = [[] for i in range(100000)]
        count = {}
        for i in range(len(nums)):
            if nums[i] in count:
                freq[count[nums[i]]].remove(nums[i])
                freq[count[nums[i]] + 1].append(nums[i])
                count[nums[i]] += 1
            else:
                freq[1].append(nums[i])
                count[nums[i]] = 1
        
        res = []
        i = len(freq)
        while(k > 0):
            i -= 1
            if len(freq[i]) != 0:
                for j in range(len(freq[i])):
                    res.append(freq[i][j])
                    k -= 1
                    if k == 0:
                        break

        return res

