class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # k most frequent elements
        num_dict = {}
        res = []
        for i in nums:
            if i in num_dict:
                num_dict[i] += 1
            else:
                num_dict[i] = 1
        
        # create a reverse dict with the frequencies as the keys and the elements as the values
        rev_dict = {}
        for key, value in num_dict.items():
            if value in rev_dict:
                rev_dict[value].append(key)
            else:
                rev_dict[value] = [key]
        
        # go through the dictionary and prepare the output
        freqs = sorted(rev_dict.keys(), reverse = True)

        for freq in freqs:
            for elem in rev_dict[freq]:
                res.append(elem)
                k -= 1
                if k <= 0:
                    return res

        return res            

